// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the BST, in worst case, H = N
class Solution {
public:
    bool isValidBST(TreeNode* root, long long L = LLONG_MIN, long long R = LLONG_MAX) {
        if(!root) return true;
        int val = root->val;
        if(val<L or val>R) return false;
        return isValidBST(root->left, L, val-1ll) and isValidBST(root->right, val+1ll, R);
    }
};
