class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> temp;


        for(int i=0 ; i<n ; i++){
            vector<int> curr(i+1, 1);
            for(int j=1 ; j<i ; j++){
                curr[j] = temp[j-1] + temp[j];

            }
            ans.push_back(curr);
            temp = curr;
        }
        return ans;
        
    }
};