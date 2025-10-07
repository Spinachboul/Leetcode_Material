class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // default: if dry day unused, we can put any lake number
        unordered_map<int, int> fullLakeDay; // lake -> last day it rained
        set<int> dryDays; // stores indices of days where rains[i] == 0

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];

                // if this lake is already full
                if (fullLakeDay.count(lake)) {
                    // find earliest dry day AFTER the last rain on this lake
                    auto it = dryDays.upper_bound(fullLakeDay[lake]);
                    if (it == dryDays.end()) return {}; // no available dry day -> flood
                    ans[*it] = lake; // dry this lake on that dry day
                    dryDays.erase(it);
                }

                // mark lake as full on this day
                fullLakeDay[lake] = i;
                ans[i] = -1; // raining day
            } else {
                // dry day — we’ll decide later which lake to dry
                dryDays.insert(i);
                ans[i] = 1; // placeholder
            }
        }

        return ans;
    }
};
