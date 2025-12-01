class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        int m = batteries.size();

        // Take the n largest as our baseline
        vector<long long> live(n);
        for (int i = 0; i < n; i++) {
            live[i] = batteries[m - n + i];
        }

        // All smaller ones contribute to "extra"
        long long extra = 0;
        for (int i = 0; i < m - n; i++) {
            extra += batteries[i];
        }

        // Try to raise the first k batteries up to the level of the next one
        for (int i = 0; i < n - 1; i++) {
            long long diff = live[i+1] - live[i];
            long long cost = diff * (long long)(i + 1);

            // Not enough extra to reach live[i+1]
            if (extra < cost) {
                return live[i] + extra / (long long)(i + 1);
            }

            // Otherwise level them up to live[i+1]
            extra -= cost;
        }

        // After leveling everything, spread the remaining extra evenly
        return live[n - 1] + extra / n;
    }
};
