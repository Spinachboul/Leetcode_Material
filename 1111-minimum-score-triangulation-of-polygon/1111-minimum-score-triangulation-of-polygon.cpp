class Solution {
private:
    int dp(int i, int j , unordered_map<long long, int> &mp, vector<int>& values){
        if(i+2 > j) return 0;

        if(i+2 == j){
            return values[i] * values[i+1] * values[j];
        }

        long long key = ((long long)i << 32) | j;
        if(mp.count(key)) return mp[key];

        int mn = INT_MAX;
        for(int k=i+1 ; k<j ; k++){
            mn = min(mn, values[i] * values[j] * values[k] 
                          + dp(i, k, mp, values) 
                          + dp(k, j, mp, values));
        }
        return mp[key] = mn;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        unordered_map<long long, int> mp;
        return dp(0, n-1, mp, values);
    }
};
