class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);

        for(int i=0 ; i<n ; i++){
            int spell = spells[i];
            long long k = (spell + success-1)/spell;
            if(k <= potions[m-1]){
                res[i] = m - (lower_bound(potions.begin() , potions.end() , k) - potions.begin());

            }
        }
        return res;
    }
};