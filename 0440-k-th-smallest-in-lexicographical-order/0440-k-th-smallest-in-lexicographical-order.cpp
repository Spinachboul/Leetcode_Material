class Solution {
public:
    int dfs(int n, long p1, long p2){
        int steps = 0;
        while( p1 <= n){
            steps += min((long)(n+1), p2) - p1;
            p1 *= 10;
            p2 *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while( k > 0){
            int step = dfs(n, curr, curr+1);
            if(step <= k){
                curr++;
                k -= step;
            }
            else{
                curr *= 10;
                k--;
            }
        }
        return curr;

        
    }
};