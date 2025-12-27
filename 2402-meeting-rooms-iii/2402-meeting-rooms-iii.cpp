class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> timer(n, 0); // when each room becomes free
        vector<int> count(n, 0);       // meetings per room

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long dur = end - start;

            int freeRoom = -1;
            long long earliestTime = LLONG_MAX;
            int earliestRoom = -1;

            // scan rooms
            for (int i = 0; i < n; i++) {
                // track earliest finishing room
                if (timer[i] < earliestTime) {
                    earliestTime = timer[i];
                    earliestRoom = i;
                }
                // pick smallest-index free room
                if (timer[i] <= start && freeRoom == -1) {
                    freeRoom = i;
                }
            }

            if (freeRoom != -1) {
                // room is free at start
                timer[freeRoom] = end;
                count[freeRoom]++;
            } else {
                // delay meeting to earliest available room
                timer[earliestRoom] += dur;
                count[earliestRoom]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
