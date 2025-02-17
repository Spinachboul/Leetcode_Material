class Solution {
private:
    void generateSequences(string& tiles, string current, unordered_set<string> &st, vector<bool> &used){
        st.insert(current);

        // add each nunused character in the current sequence
        for(int i=0 ; i<tiles.size() ; i++){
            if(!used[i]){
                used[i] = true;
                generateSequences(tiles, current + tiles[i], st, used);
                used[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string> st;
        vector<bool> used(tiles.size(), false);

        string current = "";
        generateSequences(tiles, current, st, used);
        return st.size()-1;




        
    }
};