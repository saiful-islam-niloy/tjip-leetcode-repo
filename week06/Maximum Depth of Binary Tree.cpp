// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the tree, in worst case H = N
class Solution {
public:
    int maxDepth(TreeNode* root, int depth=0) {
        if(!root) return 0;
        if(!root->left and !root->right) return depth + 1;
        return max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1));
    }
};
