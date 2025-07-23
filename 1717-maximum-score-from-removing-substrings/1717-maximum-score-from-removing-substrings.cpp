class Solution {
public:
    string fun(string &s, string &ss){
        stack<char> st;
        for(char c: s){
            if(c == ss[1] && !st.empty() && st.top() == ss[0]){
                st.pop();
            }
            else st.push(c);
        }

        string rem;

        while(!st.empty()){
            rem += st.top();st.pop();        
        }

        reverse(rem.begin() , rem.end());
        return rem;

    }
    int maximumGain(string s, int x, int y) {

        int n = s.size();
        string hp = (x>y) ? "ab" : "ba";
        string lp = hp == "ab"  ? "ba" : "ab";
        
        string firstpass = fun(s, hp);
        int len = (s.size()  - firstpass.size()) / 2;

        int totalScore= 0;
        totalScore += len * max(x, y);

        string secondpass = fun(firstpass, lp);
        int lenn = (firstpass.size() - secondpass.size())/2;
        totalScore += lenn * min(x, y);

        return totalScore;
    }
};