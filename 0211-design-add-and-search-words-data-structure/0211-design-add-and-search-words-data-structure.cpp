class TrieNode{
    public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    TrieNode(char ch) : data(ch) , isTerminal(false) {}

};

class Trie{
    TrieNode* root;

    void insertUtil(TrieNode* &root, string &word, int i=0){
        if(i==word.size()){
            root->isTerminal = true;
            return;
        }

        if(root->children.find(word[i]) == root->children.end()){
            root->children[word[i]] = new TrieNode(word[i]);
        }

        insertUtil(root->children[word[i]], word, i+1);
    }

    bool searchUtil(TrieNode* &root, string& word, int i = 0){
        if(i==word.size()){
            return root->isTerminal;
        }

        bool matched = false;

        char ch = word[i];

        if(ch == '.'){
            for(auto& [childChar, childNode] : root->children){
                matched = matched || searchUtil(childNode, word , i+1);
            }
        }
        else{
            if(root->children.find(word[i]) != root->children.end()){
                return searchUtil(root->children[word[i]], word, i+1);
            }
        }

        return matched;
    }

    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string& word){
            insertUtil(root, word);
        }
        
        bool search(string& word){
            return searchUtil(root, word);
        }

};
class WordDictionary {
public:
Trie trie;
    WordDictionary() {

        
    }
    
    void addWord(string word) {
        trie.insert(word);

        
    }
    
    bool search(string word) {
        return trie.search(word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */