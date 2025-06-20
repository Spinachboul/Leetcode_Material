class Solution {
public:
    int count(int d1, int d2, int t){
        return abs(d1-d2) + 2*t;
    }
    int maxDistance(string s, int k) {
        int north = 0, south = 0, east = 0, west = 0;
        int ans = 0;
        for(int i=0 ; i<s.size() ; i++){
            switch(s[i]){
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'W':
                    west++;
                    break;
                case 'E':
                    east++;
                    break;
            }
            int t1 = min({north, south, k});
            int t2 = min({east, west, k-t1});

            ans = max(ans, count(north, south, t1) + count(east, west, t2));
            

        }
        return ans;
        
    }
};