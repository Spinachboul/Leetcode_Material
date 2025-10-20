class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        for(auto& it: operations){
            if(it=="--X" || it == "X--"){
                ans -= 1;
            }
            else ans += 1;
        }
        return ans;
        
    }
};