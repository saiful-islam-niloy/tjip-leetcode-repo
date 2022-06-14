// TC: O(N), N = total number of nodes
// SC: O(L), L = maximum number of nodes in a layer, L = 2^log2(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        bool leftToRight = true;
        if(!root) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        while(dq.size()){
            int size = dq.size();
            vector<int> level;
            for(int i = 0; i<size; i++){
                if(leftToRight){
                    auto top = dq.front();
                    dq.pop_front();
                    level.push_back(top->val);
                    if(top->left) dq.push_back(top->left);
                    if(top->right) dq.push_back(top->right);
                }else {
                    auto top = dq.back();
                    dq.pop_back();
                    level.push_back(top->val);
                    if(top->right)dq.push_front(top->right);
                    if(top->left) dq.push_front(top->left);
                }
            }
            leftToRight = !leftToRight;
            levels.push_back(level);
        }
        
        return levels;
    }
};
