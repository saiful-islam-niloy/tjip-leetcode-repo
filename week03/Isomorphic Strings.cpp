class Solution {
   public:
    bool isIsomorphic(string s, string t, int iteration = 0) {
        unordered_map<char, char> from;

        for (int i = 0; i < s.size(); i++) {
            if (from.count(s[i]) != 0 and from[s[i]] != t[i]) {
                return false;
            }
            from[s[i]] = t[i];
        }

        if (iteration == 1) return true;

        return isIsomorphic(t, s, 1);
    }
};