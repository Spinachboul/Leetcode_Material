class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        int res = word.size();
        for(int i=0 ; i<word.size() ; i++){
            mp[word[i]]++;
        }

        for(auto& [_, a]: mp){
            int deleted = 0;
            for(auto& [_, b] : mp){
                if(a>b){
                    deleted += b;
                }
                else if(b > k + a){
                    deleted += b-(k+a);
                }
            }
            res = min(res, deleted);
        }
        return res;

        
    }
};