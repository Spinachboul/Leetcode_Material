class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> st(26);
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] != '*'){
                st[s[i] - 'a'].push(i);
            }
            else{
                for(int j=0 ; j<26 ; j++){
                    if(!st[j].empty()){
                        s[st[j].top()] = '*';
                        st[j].pop();
                        break;
                    }
                }
            }
        }
        string ans;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] != '*'){
                ans.push_back(s[i]);
            }
        }
        return ans;


        
    }
};