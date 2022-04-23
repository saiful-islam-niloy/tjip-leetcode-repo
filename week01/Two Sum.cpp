class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (seen.count(remaining)) {
                return {i, seen[remaining]};
            }

            seen.insert({nums[i], i});
        }

        return {-1, -1};
    }
};