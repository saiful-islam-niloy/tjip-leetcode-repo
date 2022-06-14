// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the tree, in worst case H = N
class Solution {
public:
    int getMaxPathSum(TreeNode* root, int& maxSum){
        if(!root) return 0;
        
        int left = getMaxPathSum(root->left, maxSum);
        int right= getMaxPathSum(root->right, maxSum);
        
        int currSum = max(left, right) + root->val;
        currSum = max(currSum, root->val);
        maxSum = max(currSum, maxSum);
        maxSum = max(maxSum, left+right+root->val);
        return currSum;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getMaxPathSum(root, maxSum);
        return maxSum;
    }
};
