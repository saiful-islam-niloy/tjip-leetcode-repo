/*
TC: O(log(N)), N = total size of nums
SC: O(1)

Disadvantage: This approach can not guarantee global maxima. 
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0;
        int R = nums.size()-1;
        
        while(L<R){
            int M = L + (R-L)/2;
            if(nums[M] > nums[M+1]) R = M;
            else L = M+1;
        }
        
        return R;
    }
};
