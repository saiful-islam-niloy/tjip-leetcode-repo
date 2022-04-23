class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freqS[257];
        int freqT[257];
        for (int i = 0; i < 257; i++) {
            freqS[i] = 0;
            freqT[i] = 0;
        }

        for (int i = 0; i < s.size(); i++) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }

        for (int i = 0; i < 257; i++)
            if (freqS[i] != freqT[i]) return false;

        return true;
    }
};