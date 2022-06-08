// TC: O(N), N = total number of nodes in the tree
// SC: O(N), N = total number of nodes in the tree, here contruct path and store in vector
class Solution {
public:
    TreeNode* getLCA(TreeNode* root, int startValue, int destValue){
        if(!root) return NULL;
        if(root->val == startValue or root->val == destValue) return root;
        
        TreeNode* left = getLCA(root->left, startValue, destValue);
        TreeNode* right = getLCA(root->right, startValue, destValue);
        
        if(left and right) return root;
        return left ? left : right;
    }
    
    void constructPath(TreeNode* root, int val, vector<char>& path, bool& found){
        if(!root or found) return;
        if(root->val == val) {
            found = true;
            return;
        }
        
        path.push_back('L');
        constructPath(root->left, val, path, found);
        if(!found) path.pop_back();
        if(!found) path.push_back('R');
        constructPath(root->right, val, path, found);
        if(!found) path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = getLCA(root, startValue, destValue);
        vector<char> pathStartValue;
        vector<char> pathDestValue;
        bool found = false;
        constructPath(root, startValue, pathStartValue, found);
        found = false;
        constructPath(root, destValue, pathDestValue, found);
        string shortestPath = "";
        for(auto dir : pathStartValue)
            shortestPath.push_back('U');
        for(auto dir : pathDestValue)
            shortestPath.push_back(dir);
        return shortestPath;
    }
};
