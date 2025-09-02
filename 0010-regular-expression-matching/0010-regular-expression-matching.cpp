class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();

        bool firstM = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if(p.size()>=2 && p[1] == '*'){
            return (isMatch(s, p.substr(2)) || (firstM && isMatch(s.substr(1), p)));

        }
        else{
            return firstM && isMatch(s.substr(1), p.substr(1));
        }

        
    }
};