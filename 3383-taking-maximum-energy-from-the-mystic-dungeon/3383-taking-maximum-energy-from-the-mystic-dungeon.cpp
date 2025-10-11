class Solution {
    using ll = long long;
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();

        int ans = INT_MIN;

        for(int i=n-k ; i<n ; i++){
            int s = 0;
            for(int j=i ; j>=0 ; j-=k){
                s += energy[j];
                ans = max(ans, s);
            }
        }
        return ans;



        
    }
};