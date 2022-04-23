class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        if (intervals.size() == 1) return intervals;

        int x = intervals[0][0];
        int y = intervals[0][1];
        int i = 1;
        int size = intervals.size();

        while (i < size) {
            while (true) {
                if (intervals[i][0] >= x && intervals[i][0] <= y) {
                    y = max(y, intervals[i][1]);
                    i++;
                    if (i == size) break;
                } else {
                    merged.push_back({x, y});

                    x = intervals[i][0];
                    y = intervals[i][1];

                    i++;

                    break;
                }
            }
        }

        merged.push_back({x, y});

        return merged;
    }
};