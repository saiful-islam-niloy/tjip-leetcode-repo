class Solution {
public:
    int getKthLargest(vector<int> &nums, int start, int end){
        int pivot = end;
        int ptr = start;
        for(int i=start; i<=end; i++){
            if(nums[i]<nums[pivot]) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
            if(i==end){
                swap(nums[ptr], nums[pivot]);
                pivot = ptr;
            }
        }
        return pivot;
    }
    
    int quick_partition(vector<int> &nums, int k, int start, int end){
        int pivot = getKthLargest(nums, start, end);
        if(pivot+k == nums.size()) return nums[pivot];
        
        else if(pivot > nums.size()-k)
            return quick_partition(nums, k, start, pivot-1);
        else
            return quick_partition(nums, k, pivot+1, end);
        
        return -1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quick_partition(nums, k, 0, nums.size()-1);
    }
};
