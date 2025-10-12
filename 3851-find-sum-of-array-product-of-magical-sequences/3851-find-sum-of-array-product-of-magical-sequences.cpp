#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MOD = 1'000'000'007;

int64 modpow(int64 a, int64 e) {
    int64 r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int64 inv(int64 x) { return modpow(x, MOD - 2); }

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = (int)nums.size();

        // Precompute factorials and inverse factorials up to m.
        // We'll multiply final DP result by m! (multinomial factor),
        // and during DP we divide by r! by multiplying invfact[r].
        vector<int64> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; ++i) fact[i] = fact[i-1] * i % MOD;
        invfact[m] = inv(fact[m]);
        for (int i = m; i >= 1; --i) invfact[i-1] = invfact[i] * i % MOD;

        // Precompute powNums[i][r] = nums[i]^r % MOD for r = 0..m
        vector<vector<int64>> powNums(n, vector<int64>(m + 1, 1));
        for (int i = 0; i < n; ++i) {
            for (int r = 1; r <= m; ++r) powNums[i][r] = powNums[i][r-1] * nums[i] % MOD;
        }

        // DP dimensions:
        // dp_used[used][carry][setBits] => value
        // We'll iterate i = 0..n-1; keep current and next layers to save memory.
        // Ranges:
        // used: 0..m
        // carry: 0..m (safe upper bound)
        // setBits: 0..k (we only care up to k; any higher can be dropped)
        auto make3d = [&](int U, int C, int S) {
            return vector<vector<vector<int64>>>(U, vector<vector<int64>>(C, vector<int64>(S, 0)));
        };

        // current DP layer for processed indices up to i-1
        auto dp = make3d(m + 1, m + 1, k + 1);
        dp[0][0][0] = 1; // nothing chosen, no carry, no set bits => factor 1

        // Iterate through each index (bit position)
        for (int i = 0; i < n; ++i) {
            auto nxt = make3d(m + 1, m + 1, k + 1);

            // For each DP state so far
            for (int used = 0; used <= m; ++used) {
                for (int carry = 0; carry <= m; ++carry) {
                    for (int setBits = 0; setBits <= k; ++setBits) {
                        int64 curVal = dp[used][carry][setBits];
                        if (!curVal) continue;

                        // we can pick index i any r times from 0..(m-used)
                        int maxR = m - used;
                        for (int r = 0; r <= maxR; ++r) {
                            // total ones at this bit before carrying = carry + r
                            int total = carry + r;
                            int bitHere = total & 1; // 0 or 1 in final at this position
                            int newSetBits = setBits + bitHere;
                            if (newSetBits > k) break; // we don't need states with more than k set bits

                            int newCarry = total >> 1; // carry to next higher bit (integer)

                            // contribution multiplier:
                            // multiply current factor by nums[i]^r / r! (mod)
                            int64 mult = powNums[i][r] * invfact[r] % MOD;

                            int64 add = curVal * mult % MOD;
                            nxt[used + r][newCarry][newSetBits] += add;
                            if (nxt[used + r][newCarry][newSetBits] >= MOD) nxt[used + r][newCarry][newSetBits] -= MOD;
                        }
                    }
                }
            }

            dp.swap(nxt); // move to next index
        }

        // After processing all indices 0..n-1, we might still have carry left.
        // The remaining carry is a normal integer; its binary representation contributes popcount(carry) to set bits.
        // We need used == m and total set bits == k.
        int64 ans = 0;
        for (int carry = 0; carry <= m; ++carry) {
            int pop = __builtin_popcount(carry);
            for (int setBits = 0; setBits <= k; ++setBits) {
                if (setBits + pop != k) continue;        // final total must be k
                int64 val = dp[m][carry][setBits];      // we've used exactly m picks
                if (!val) continue;
                // multiply by m! (multinomial permutations)
                val = val * fact[m] % MOD;
                ans += val;
                if (ans >= MOD) ans -= MOD;
            }
        }

        return (int)ans;
    }
};
