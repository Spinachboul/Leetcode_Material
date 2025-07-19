class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> res;
        for(auto& it: folder){
            bool is = false
            string prefix = it;

            while(!prefix.empty()){
                size_t pos = prefix.find_last_of('/');
                if(pos == string::npos) break;

                prefix = prefix.substr(0, pos);

                if(st.count(prefix)){
                    is = true;
                    break;
                }

            }
            if(!is){
                res.push_back(it);
            }
        }
        return res;
        
    }
};