class Solution {
private:
    int solve(int n, unordered_map<int, int> mp){
        if(n==0 || n==1) return 1;

        if(mp.find(n) == mp.end()){
            mp[n] = solve(n-1, mp) + solve(n-2, mp);
        }

        return mp[n];
    }
public:
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return solve(n, mp);
        
    }
};