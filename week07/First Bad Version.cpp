// TC: O(log(N)), N = total number of versions
// SC: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1;
        int R = n;
        int M;
        while(L<R){
            M = L + (R-L)/2;
            if(isBadVersion(M)) R = M;
            else L = M+1;
        }
        return R;
    }
};
