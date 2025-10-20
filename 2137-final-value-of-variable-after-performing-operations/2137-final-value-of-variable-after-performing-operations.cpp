class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            string curr = operations[i];
            if(curr[0] == '-'){
                ans -= 1;
            }
            else if(curr.back() == '-'){
                ans -= 1;
            }
            else ans += 1;
        }
        return ans;
        
    }
};