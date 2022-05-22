class TrieNode{
    public: 
        string word;
        TrieNode *next[26];
    
        TrieNode(){
            word = "";
            for(int i=0; i<26; i++)
                next[i] = NULL;
        }
};

class Solution {
public:
    TrieNode* generateTrie(vector<string>& products){
        TrieNode* root = new TrieNode();
        
        for(auto& product : products){
            TrieNode* curr = root;
            for(auto c : product){
                int order = c - 'a';
                if(curr -> next[order] == NULL) curr -> next[order] = new TrieNode();
                curr = curr -> next[order]; 
            }
            curr -> word = product;
        }
        return root;
    }
    
    void dfs(TrieNode* root, vector<string>& words){
        if(root == NULL or words.size() == 3) return;
        if(root -> word.size() > 0 and words.size()<4) words.push_back(root -> word);
        for(int i=0; i<26; i++){
            dfs(root -> next[i], words);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = generateTrie(products);
        vector<vector<string> > suggestions;
        
        for(auto c : searchWord){
            int order = c -'a';
            root = root and root->next[order] ? root -> next[order] : NULL;
            vector<string> words;
            dfs(root, words);
            suggestions.push_back(words);
        }
        
        return suggestions;
    }
};
