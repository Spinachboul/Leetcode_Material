class TrieNode{
public:
    TrieNode* mp[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i=0 ; i<26 ; i++){
            mp[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
        
    }
    
    void insert(string word) {  
        // create a node for the trie
        TrieNode* node = root;

        // traverse through the characters
        for(char c : word){
            // get the index of the character and check if it is null in the vector
            int index = c - 'a';
            if(node->children[index] == nullptr){
                // we simply introduce a new node here
                node->children[index] = new TrieNode();
            }
            // otherwise we assign the node to the children of the current node in the trie
            node = node->children[index];
        }
        node->isEnd = true;
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */