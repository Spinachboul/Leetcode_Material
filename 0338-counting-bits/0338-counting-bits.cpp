class Solution {
public:
    int fun(int x){
        int count = 0;
        while(x){
            count += (x &1);
            x >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0 ; i<=n; i++){
            int count = fun(i);
            ans[i] = count;
        }
        return ans;
        
    }
};