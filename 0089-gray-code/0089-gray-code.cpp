class Solution {
public:
    vector<int> grayCode(int n) {
        // first we need to find the max limit
        int mx = (1 << n);
        vector<int> ans;
        ans.push_back(0);

        for(int i=1 ; i<mx ; i++){
            ans.push_back(i ^ (i >> 1));
        }
        return ans;


        
    }
};