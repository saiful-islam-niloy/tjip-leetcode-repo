// TC: O(N), N = total number of nodes in the tree
// SC: O(L), L = maximum number of nodes in each level, in worst case, L = 2^log2(N)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> Q;
        Q.push(root);
        
        while(Q.size()){
            int size = Q.size();
            for(int i=0; i<size; i++){
                auto top = Q.front();
                Q.pop();
                if(top->left) Q.push(top->left);
                if(top->right) Q.push(top->right);
                if(i != size -1) top->next = Q.front();
            }
        }
        
        return root;
    }
};
