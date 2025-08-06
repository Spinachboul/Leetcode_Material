class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        int m = searchWord.size();

        vector<vector<string>> ans;

        sort(products.begin() , products.end());
        string prefix = "";
        for(char ch : searchWord){
            prefix += ch;
            vector<string> curr;
            int count = 0;
            for(auto& it: products){
                if(it.substr(0, prefix.size()) == prefix){
                    count++;
                    curr.push_back(it);
                    if(count == 3) break;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};