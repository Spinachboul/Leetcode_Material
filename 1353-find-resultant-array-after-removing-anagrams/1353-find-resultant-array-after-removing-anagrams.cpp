class Solution {
private:
    vector<int> score(string& word){
        vector<int> res(26, 0);

        for(char c : word){
            res[c - 'a']+=1;
        }
        return res;
        
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {

        int n = words.size();
        vector<string> res;
        vector<int>preScore = score(words[0]);
        res.push_back(words[0]);


        for(int i=1 ; i<n ; i++){
            vector<int> currScore = score(words[i]);
            if(currScore != preScore){
                res.push_back(words[i]);
                preScore = currScore;
            }
        }
        return res;


    }
};