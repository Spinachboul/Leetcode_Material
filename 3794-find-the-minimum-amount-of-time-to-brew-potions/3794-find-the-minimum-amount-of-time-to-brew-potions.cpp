class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<ll> times(n);

        for(int j=0 ; j<m ; j++){
            ll curr = 0;
            for(int i=0 ; i<n ; i++){
                curr  = max(curr, times[i]) + mana[j]*skill[i];
            }

            times[n-1] = curr;
            for(int i=n-2 ; i>=0 ; i--){
                times[i] = times[i+1] - skill[i+1] * mana[j];
            }

        }
        return times[n-1];

    }
};