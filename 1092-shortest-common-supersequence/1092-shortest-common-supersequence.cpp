class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1 , vector<int> (n2+1, 0));
        
        // for when str2 is empty, fill all the rows with row
        for(int row = 0 ; row <=n1 ; row++){
            dp[row][0] = row;
        }

        // for when str1 is empty, fill all the columns with col
        for(int col = 0 ; col <= n2;col++){
            dp[0][col] = col;
        }

        // fill the dp table
        for(int row= 1 ; row <= n1 ; row++){
            for(int col = 1 ; col <= n2 ; col++){
                if(str1[row-1] == str2[col-1]){
                    dp[row][col] = dp[row-1][col-1] +1;

                }
                else{
                    dp[row][col] = min(dp[row-1][col] , dp[row][col-1]) +1;
                }
            }
        }

        string ans = "";

        int row = n1, col = n2;
        while(row > 0 && col > 0){
            if(str1[row-1] == str2[col-1]){
                ans += str1[row-1];
                row--;
                col--;
            }
            else if(dp[row-1][col] < dp[row][col-1]){
                ans += str1[row-1];
                row--;
            }
            else{
                ans += str2[col-1];
                col--;
            }
        }

        while(row > 0){
            ans += str1[row-1];
            row--;
        }

        while(col > 0){
            ans += str2[col-1];
            col--;
        }

        reverse(ans.begin() , ans.end());
        return ans;

        
    }
};