// TC: O(N), N = total number of nodes
// SC: O(H), H = max height of the binary tree, in worst case H = N
class Solution {
public:
    int getKthSmallest(TreeNode* root, int& k){
        if(!root) return -1;
        
        int R = getKthSmallest(root->left, k);
        k--;
        if(k == 0) return root->val;
        int L = getKthSmallest(root->right, k);
        
        return max(L,R);
    }
    int kthSmallest(TreeNode* root, int k) {
        return getKthSmallest(root, k);
    }
};
