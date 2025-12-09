class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> right, left;

        for (int x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;

            long long leftCnt = left[2 * mid];
            long long rightCnt = right[2 * mid];

            ans = (ans + leftCnt * rightCnt) % MOD;

            left[mid]++;
        }

        return ans;
    }
};
