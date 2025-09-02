class Solution {
private:
    bool dp(int i, int j, string& s, string& p, vector<vector<int>> &memo){
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        bool ans;

        if(j == p.size()){
            ans = (i == s.size());

        }
        else{
            bool firstM = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

            if(j + 1 < p.size() && p[j+1] == '*'){
                ans = (dp(i, j+2, s, p, memo) || (firstM && dp(i+1, j, s, p, memo)));

            }
            else{
                ans = firstM && dp(i+1, j+1, s, p, memo);
            }
        }
        memo[i][j] = ans;
        return ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size()+1, vector<int>(p.size()+1, -1));

        return dp(0, 0, s, p, memo);
        
    }
};