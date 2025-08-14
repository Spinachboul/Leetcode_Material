class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i=0 ; i+2 < n ; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string c = num.substr(i,3);
                if(c > ans) ans = c;
            }

        }
        return ans;
        
    }
};