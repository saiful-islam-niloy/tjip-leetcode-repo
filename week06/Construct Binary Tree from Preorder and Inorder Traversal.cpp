// TC: O(N), N = total number of nodes
// SC: O(H), H = maximum height of the tree, in worst case, H = N
class Solution {
public:
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int L, int R, int& pos, unordered_map<int,int>& storage){
        if(L>R) return NULL;
        TreeNode* currRoot = new TreeNode(preorder[pos++]);
        int M = storage[currRoot->val];
        currRoot->left = constructTree(preorder, inorder, L, M-1, pos, storage);
        currRoot->right = constructTree(preorder, inorder, M+1, R, pos, storage);
        return currRoot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> storage;
        for(int i=0; i<inorder.size(); i++) storage[inorder[i]] = i;
        int pos = 0;
        return constructTree(preorder, inorder, 0, inorder.size()-1, pos, storage);
    }
};
