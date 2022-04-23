class Solution {
   public:
    bool isValid(string s) {
        vector<char> arr;

        for (auto ch : s) {
            if (ch == '(' or ch == '[' or ch == '{')
                arr.push_back(ch);
            else {
                int top = arr.size() - 1;
                if (arr.size() == 0)
                    return false;
                else if (ch == ')' and arr[top] == '(')
                    arr.pop_back();
                else if (ch == '}' and arr[top] == '{')
                    arr.pop_back();
                else if (ch == ']' and arr[top] == '[')
                    arr.pop_back();
                else
                    return false;
            }
        }
        return arr.size() == 0 ? true : false;
    }
};