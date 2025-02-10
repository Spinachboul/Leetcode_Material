class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(int i=0 ; i<s.size() ; i++){
            if(isdigit(s[i])){
                if(!res.empty() && !isdigit(res.back())){
                    res.pop_back();
                }
                
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};
