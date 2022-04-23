class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long temp = 1;
        int zero_cnt  = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero_cnt++;
            } else {
                temp *= nums[i];
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0 && zero_cnt == 1)
                nums[i] = temp;
            else if(nums[i] == 0 && zero_cnt > 1)
                nums[i] = 0;
            else if(nums[i] != 0 && zero_cnt>0)
                nums[i] = 0;
            else 
                nums[i] = temp / nums[i];   
        }
        
        return nums;
    }
}
