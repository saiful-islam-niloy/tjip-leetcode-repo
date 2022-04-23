class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int slow = 0;
        int fast = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= prices[fast]) {
                profit += prices[fast] - prices[slow];
                fast = i;
                slow = i;
            } else {
                fast++;
                if (i == prices.size() - 1)
                    profit += prices[fast] - prices[slow];
            }
        }

        return profit;
    }
};