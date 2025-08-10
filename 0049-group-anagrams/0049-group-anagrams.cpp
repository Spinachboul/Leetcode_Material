class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(string it: strs){
            string curr =it;
            sort(curr.begin() , curr.end());
            mp[curr].push_back(it);

        }

        for(auto& it: mp){
            ans.push_back(it.second);
        }
        return ans;

        
        
    }
};