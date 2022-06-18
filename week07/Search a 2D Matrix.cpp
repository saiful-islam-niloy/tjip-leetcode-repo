// TC: O(log(M*N)), M = size of row, N = size of column
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int L = 0;
        int R = colSize * rowSize -1;
        int M;
        
        while(L<=R){
            M = L + (R-L)/2;
            int curr = matrix[M/colSize][M%colSize];
            if(curr == target) return true;
            else if(curr < target) L = M + 1;
            else R = M - 1;
        }
        
         return false;
    }
};
