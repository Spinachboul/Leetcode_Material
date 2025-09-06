class Solution {
    using ll = long long;
private:
    ll get(int num){
        int i=1;
        int base = 1;
        ll cnt = 0;
        while(base <= num){
            cnt += 1ll * (i+1)/2 * (min(num, 2 * base - 1) - base + 1);
            i++;
            base *= 2;
        }
        return cnt;
    }

public:

    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for(auto& it: queries){
            res += (get(it[1]) - get(it[0] -1) +1)/2;
        }
        return res;
        
    }
};