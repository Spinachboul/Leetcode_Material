class Solution {
public:
    void dfs(int currNum, int limit, vector<int>& res){
        if(currNum > limit) return;

        res.push_back(currNum);
        // append the digits from 0 to 9
        for(int i=0 ; i<=9 ; i++){
            int next = currNum * 10 + i;
            if(next <= limit){
                // call the recursion
                dfs(next, limit, res);
            }
            else{
                break;
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1 ; i<=9 ; i++){
            dfs(i, n, res);
        }
        return res;
        
    }
};