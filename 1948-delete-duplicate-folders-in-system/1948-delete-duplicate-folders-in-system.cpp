class Trie{
    public:
    string serial;
    unordered_map<string, Trie*> children;
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // using a trie to make a folder structure
        Trie* root = new Trie();

        // Construct the tree
        for(const vector<string>& path : paths){
            Trie* curr = root;
            for(const string& node : path){
                if(!curr->children.count(node)){
                    // if we dont hav any children, then make it a new child
                    curr->children[node] = new Trie();

                }

                // otherwise append in the list of children for easy serialization
                curr = curr->children[node];
            }
        }

        // hash table record the occurance times of each serialized representation
        unordered_map<string, int> freq;
        
        // left, right, root
        function<void(Trie*) > construct  = [&] (Trie* node){
            // if it is a leaf node, then the seriaization is not possible, so make it an empty string
            if(node->children.empty()) return;

            vector<string> v;

            for(const auto&[folder, child] : node->children){
                construct(child);

                v.push_back(folder + "("  + child->serial + ")");

            }

            // sort to prevent issues with the ordering
            sort(v.begin() , v.end());

            // now since we have sorted, we will form the serail strings
            for(auto& s: v){
                node->serial += move(s);
            }

            // then add this serial to the hash table
            freq[node->serial]++;
        };


        // call the construct function outside the for actually building up the tree
        construct(root);

        vector<vector<string>> ans;
        vector<string> path;


        // record the path from the root to the current node
        function<void(Trie*) >  operate = [&] (Trie* node){
            // if we have duplicate, then needs to be deleted
            if(freq[node->serial] > 1) return;

            // if unique, then add it to the path
            if(!path.empty()){
                ans.push_back(path);
            }

            // now traverse in the trie and then perform recursion on the corresponding subtrees
            for(const auto& [folder, child] : node->children){
                path.push_back(folder);
                operate(child);
                // to backtrack, we need to pop again to start with a new node
                path.pop_back();
            }
        };
        operate(root);
        return ans;




        
    }
};