class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        int minSize = INT_MAX;
        int similarIdx = 0;
        for (int i = 0; i < strs.size(); i++) {
            minSize = min(minSize, (int)strs[i].size());
        }

        for (int i = 0; i < minSize; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] != strs[j][i]) {
                    return strs[0].substr(0, similarIdx);
                    break;
                }
            }
            similarIdx++;
        }

        return strs[0].substr(0, similarIdx);
    }
};
