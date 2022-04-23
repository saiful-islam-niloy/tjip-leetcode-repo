class Solution {
   public:
    const static int length = 1e4 + 5;
    int BASE = 257;
    long long int myHash[length];
    long long int po[length];
    long long int MOD = 1e9 + 7;

    long long getHash(int l, int r) {
        if (l == 0) return myHash[r];
        long long temp = (myHash[r] - myHash[l - 1] * po[r - l + 1] % MOD + MOD) % MOD;
        return temp;
    }

    void generatePower() {
        po[0] = 1;
        for (int i = 1; i < length; i++)
            po[i] = (po[i - 1] * BASE) % MOD;
    }

    void generateHaystackHash(string key) {
        if (key.size() >= 1) myHash[0] = int(key[0]);
        for (int i = 1; i < key.size(); i++)
            myHash[i] = (myHash[i - 1] * BASE + int(key[i])) % MOD;
    }

    long long generateNeedleHash(string key) {
        long long needleHash = 0;

        for (int i = 0; i < key.size(); i++) {
            needleHash = ((needleHash * BASE) + int(key[i])) % MOD;
        }

        return needleHash;
    }

    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        long long needleHash = generateNeedleHash(needle);
        generateHaystackHash(haystack);
        generatePower();

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (needleHash == getHash(i, i + needle.size() - 1)) {
                return i;
            }
        }
        return -1;
    }
};