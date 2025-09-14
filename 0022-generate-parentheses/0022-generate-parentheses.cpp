class Solution {
private:
    void helper(int open, int close, int n, string s, vector<string> &ans){
        if(open + close == 2*n){
            ans.push_back(s);
        }

        if(open < n){
            helper(open+1, close, n, s+ "(" , ans);
        }
        if(close < open){
            helper(open, close + 1, n, s + ")" , ans);
        }


    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, n, "" , ans);
        return ans;
        
    }
};