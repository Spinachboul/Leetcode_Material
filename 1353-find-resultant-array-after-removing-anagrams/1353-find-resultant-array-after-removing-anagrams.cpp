class Solution {
private:
    bool isAna(string& w1, string& w2){
        sort(w1.begin() , w1.end());
        sort(w2.begin() , w2.end());
        return w1 == w2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {

        int n = words.size();
        vector<bool> toPick(n, false);
        vector<string> ans;
        for(int i=1 ; i<n ; i++){
            string w1 = words[i], w2 = words[i-1];
            if(isAna(w1, w2)){
                toPick[i] = true;
            }
        }

        for(int i=0 ; i<n ; i++){
            if(!toPick[i]){
                ans.push_back(words[i]);
            }
        }

        return ans;

    }
};