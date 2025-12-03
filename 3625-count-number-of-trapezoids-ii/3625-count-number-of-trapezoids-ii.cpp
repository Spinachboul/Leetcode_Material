class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9+7;

        unordered_map<float, vector<float>> sI;
        unordered_map<int, vector<float>> mS;

        int ans = 0;

        for(int i=0 ; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j=i+1 ; j<n ; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x1 - x2;
                int dy = y1 - y2;

                float k, b;

                if(x2 == x1) {// it is the same slope
                    k = inf;
                    b = x1;
                }

                else{
                    // slope calculation
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float) (y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                sI[k].push_back(b);
                mS[mid].push_back(k);

            }


        }

        for(auto& [_, sti] : sI){
            if(sti.size() == 1){
                continue;
            }

            // get the count of all the intercepts
            map<float, int> cnt;
            for(float  b : sti){
                cnt[b]++;
            }

            // this is all the figures -> trapeziums + parallelograms
            int sum = 0;

            for(auto& [_, count] : cnt){
                ans += sum * count;
                sum += count;
            }
        }

        for(auto& [_, mts] : mS){
            if(mts.size() == 1){
                continue;
            }

            map<float, int> cnt;
            for(float k : mts){
                cnt[k]++;
            }


            int sum = 0;
            for(auto& [_, count]: cnt){
                // this is to remove all the parallelograms
                // and will only include the trapeziums
                ans -= sum * count;
                sum += count;
            }
        }
        return ans % inf;

        
    }
};