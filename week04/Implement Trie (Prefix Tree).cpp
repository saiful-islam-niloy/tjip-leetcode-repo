class Node {
    public:
        bool isWord;
        Node *next[26];
        Node(){
            isWord = false;
            for(int i=0; i<26; i++)
                next[i] = NULL;
        }
};



class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(auto c : word){
            int order = c - 'a';
            if(curr -> next[order] == NULL) curr -> next[order] = new Node();
            curr = curr -> next[order];
        }
        curr -> isWord = true;
    }
    
    bool search(string word, bool isPrefixSearch=false) {
        Node *curr = root;
        for(auto c : word){
            int order = c - 'a';
            if(curr -> next[order] == NULL) return false;
            curr = curr -> next[order];
        }
        return curr -> isWord || isPrefixSearch;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
