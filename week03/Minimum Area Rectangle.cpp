
class Solution {
   public:
    int PRM = 40001;
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> x2y;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            x2y.insert(x * PRM + y);
        }

        int n = points.size();
        int minArea = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x2 = points[i][0];
                int y2 = points[i][1];
                int x4 = points[j][0];
                int y4 = points[j][1];

                if (x2 != x4 and y2 != y4) {
                    if (x2y.count(PRM * x2 + y4) and x2y.count(PRM * x4 + y2)) {
                        minArea = min(minArea, abs(x2 - x4) * abs(y2 - y4));
                    }
                }
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};