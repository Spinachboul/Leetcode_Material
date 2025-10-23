class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() >2){
            string ss;
            for(int i=1 ; i<s.size() ; i++){
                int curr = s[i] - '0';
                int prev = s[i-1] - '0';
                int sum  = (curr + prev) % 10;
                ss.push_back(sum + '0');

            }
            s = ss;
        }


        return s[0] == s[1];



        
    }
};