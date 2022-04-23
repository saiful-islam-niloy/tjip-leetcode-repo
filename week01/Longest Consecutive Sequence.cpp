class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uSet;

        for (auto num : nums) uSet.insert(num);

        int cnt;
        int max_cnt = 0;
        int curr_num;

        for (auto itr = uSet.begin(); itr != uSet.end(); itr++) {
            if (uSet.count(*itr - 1) == 0) {
                cnt = 1;
                curr_num = *itr;

                while (uSet.count(curr_num + 1) == 1) {
                    cnt++;
                    curr_num += 1;
                }

                max_cnt = max(max_cnt, cnt);
            }
        }

        return nums.size() == 0 ? 0 : max(max_cnt, cnt);
    }
};