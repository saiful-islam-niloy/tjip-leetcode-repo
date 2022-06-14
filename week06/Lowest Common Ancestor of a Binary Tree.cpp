// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the tree, in worst case H = N
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val or root->val == q->val) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left and right) return root;
        return left ? left : right;
    }
};
