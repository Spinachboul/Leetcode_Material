class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        // all 1 length substrings are palindromes
        for(int i=0 ; i<n ; i++){
            dp[i][i] = true;
        }

        // if substrings of length 2 are palindrome or not
        for(int i=0 ; i+1<n ; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ans = {i, i+1};
            }
        }

        for(int diff = 2  ; diff < n ; diff++){
            for(int i=0 ; i<n-diff ; i++){
                int j = i + diff;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans = {i, j};
                }

            }
        }

        return s.substr(ans[0] , ans[1] - ans[0] + 1);


        
    }
};