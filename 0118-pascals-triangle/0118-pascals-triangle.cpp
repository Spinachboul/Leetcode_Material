class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({1});
        if(n > 1) res.push_back({1,1});

        for(int i=2 ; i<n ; i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j=1 ; j<i ; j++){
                int x = res[i-1][j-1] + res[i-1][j];
                curr.push_back(x);
            }
            curr.push_back(1);
            res.push_back(curr);
        }
        return res;
    }
};