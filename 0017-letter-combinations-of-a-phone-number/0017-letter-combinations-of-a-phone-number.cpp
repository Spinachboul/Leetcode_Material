class Solution {
unordered_map<int, string> mp = {
    {1, ""},
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
    {0, ""}
};

private:
    void solve(int index, string digit, string output, vector<string> &ans){
        if(index>=digit.size()){
            ans.push_back(output);
            return;
        }

        int num = digit[index] - '0';

        string value = mp[num];

        for(int i=0 ; i<value.size() ; i++){
            output.push_back(value[i]);
            solve(index+1, digit, output, ans);
            output.pop_back();
        }


    }
public:
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        if(digit.size() <= 0){
            return ans;
        } 

        int index = 0;
        string output;
        solve(index, digit, output, ans);
        return ans;

        
    }
};