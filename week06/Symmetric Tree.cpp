// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the tree
class Solution {
public:
    bool checkSymmetry(TreeNode* left, TreeNode* right){
        if(!left or ! right) return left == right;
        if(left->val != right->val) return false;
        return checkSymmetry(left->left, right->right) and checkSymmetry(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkSymmetry(root->left, root->right);
    }
};
