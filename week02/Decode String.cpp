class Solution {
   public:
    int reverseNum(stack<int> &digit) {
        int revNum = 0;
        while (digit.size()) {
            revNum = revNum * 10 + digit.top();
            digit.pop();
        }

        return revNum;
    }
    int generateNum(stack<int> &freq) {
        int num = 0;
        stack<int> digit;

        if (freq.size())
            if (freq.top() == -1)
                freq.pop();
        while (freq.size()) {
            digit.push(freq.top());
            freq.pop();

            if (freq.size() == 0) break;
            if (freq.top() == -1) {
                break;
            }
        }
        return reverseNum(digit);
    }

    string generateStr(stack<char> &val) {
        string str = "";
        while (val.size()) {
            str += val.top();
            val.pop();
            if (val.size() == 0) break;
            if (val.top() == '[') {
                val.pop();
                break;
            }
        }

        reverse(str.begin(), str.end());

        return str;
    }

    string decodeString(string s) {
        stack<int> freq;
        stack<char> val;
        string decode = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' and s[i] <= '9')
                freq.push(s[i] - '0');
            else if (s[i] >= 'a' and s[i] <= 'z')
                val.push(s[i]);
            else if (s[i] == '[') {
                freq.push(-1);
                val.push('[');
            } else if (s[i] == ']') {
                decode = "";

                // freq.pop();
                int times = generateNum(freq);
                string value = generateStr(val);

                for (int i = 0; i < times; i++)
                    decode += value;

                for (int i = 0; i < decode.size(); i++)
                    val.push(decode[i]);
            }
        }

        decode = generateStr(val);
        int outerNum = generateNum(freq);
        if (outerNum > 0) {
            string temp = decode;
            decode = "";
            for (int i = 0; i < outerNum; i++)
                decode += temp;
        }

        return decode;
    }
};