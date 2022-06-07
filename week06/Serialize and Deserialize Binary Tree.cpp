/*
Serialize
TC: O(N), N = total number of nodes in the tree
SC: O(H), H = height of the tree, in worst case, H = N
Deserialize
TC: O(N), N = total number of nodes in the tree
SC: O(N), N = total number of nodes, storing nodes value in vector
*/
class Codec {
public:
    string getSerialised(TreeNode* root){
        if(!root) return to_string(INT_MAX)+"#";
        return to_string(root->val) +"#" + getSerialised(root->left)  + getSerialised(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = getSerialised(root);
        return data;
    }

    void makeNodeArray(vector<int>& nodes, string& data){
        string num = "";
        for(int i=0; i<data.size(); i++){
            if(data[i] != '#') num.push_back(data[i]);
            else {
                nodes.push_back(stoi(num));
                num.clear();
            }
        }
    }
    
    TreeNode* constructTree(vector<int>& nodes, int& pos){
        if(nodes[pos] == INT_MAX) {
            pos++;
            return NULL;
        }
        TreeNode* currRoot = new TreeNode(nodes[pos++]);
        currRoot->left = constructTree(nodes, pos);
        currRoot->right = constructTree(nodes, pos);
        return currRoot;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data;
        vector<int> nodes;
        makeNodeArray(nodes, data);
        int pos = 0;
        return constructTree(nodes, pos);
    }
};
