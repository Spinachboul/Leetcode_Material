class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9+7;

        int n = corridor.size();

        // collect all the indices
        vector<int> seats;
        for(int i=0;  i<n ; i++){
            if(corridor[i] == 'S') seats.push_back(i);
        }

        int totalSeats = seats.size();
        if(totalSeats == 0 || totalSeats % 2== 1) return 0;
        
        long long ans = 1;

        // find the gaps between the adjacent pair of seats
        for(int i=2 ; i<totalSeats ; i+=2){
            int s1 = seats[i-1];
            int s2 = seats[i];

            int plants = s2 - s1 - 1;
            ans = (ans * (plants + 1)) % MOD;
        }

        return (int)ans;

    



        
        
    }
};