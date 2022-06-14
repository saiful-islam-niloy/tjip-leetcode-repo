// TC: O(NH), N = total number of nodes, H = height of the tree
// SC: O(H), H = height of the tree
class Solution {
public:
    TreeNode* collectLeafNodes(vector<int>& level, TreeNode* root){
        if(root == NULL) return NULL;
        if(root->left == NULL and root->right == NULL) {
            level.push_back(root->val);
            return root;
        }
        TreeNode* left = collectLeafNodes(level, root->left);
        TreeNode* right = collectLeafNodes(level, root->right);
        if(left != NULL) {
            root ->left = NULL;
            delete left;
        }
        if(right != NULL) {
            root -> right = NULL;
            delete right;
        }
        return NULL;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        vector<vector<int>> levels;
        if(root == NULL) return {};
        while(true){
            if(root->left == NULL and root->right == NULL){
                levels.push_back({root->val});
                root= NULL;
                break;
            }
            vector<int> level;
            collectLeafNodes(level, root);
            levels.push_back(level);
            
        }
        return levels;
    }
};
