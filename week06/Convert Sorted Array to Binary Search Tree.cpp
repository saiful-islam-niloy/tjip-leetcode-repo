// TC: O(N), N = total number of nodes in the tree
// SC: O(H), H = height of the tree
class Solution {
public:
    TreeNode* constructTree(vector<int>& nums, int L, int R){
        if(L>R) return NULL;
        int M = L + (R-L)/2;
        TreeNode* currRoot = new TreeNode(nums[M]);
        currRoot->left = constructTree(nums, L, M-1);
        currRoot->right = constructTree(nums, M+1, R);
        return currRoot;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
};
