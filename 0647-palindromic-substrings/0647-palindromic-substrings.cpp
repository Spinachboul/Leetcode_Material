class Solution {
private:
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));


        for(int l = 1 ; l<=n ; l++){
            for(int i=0 ; i+l-1 < n ; i++){
                int j  = i + l -1;
                if(s[i] == s[j]){
                    if(j-i<=2 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        count++;
                    }
                }
            }
        }
        return count;

        
    }
};