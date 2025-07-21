class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for(int i=0; i+2< s.size(); i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                s[i] = '*';
            }
        }

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '*'){
                continue;
            }
            else res += s[i];
        }
        return res;
        
    }
};