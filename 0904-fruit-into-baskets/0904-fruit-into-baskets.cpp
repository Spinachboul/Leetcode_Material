class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        // longest continious subarray where we nly have 2 values of elements. frequency can we anything

        unordered_map<int, int> mp;

        int left = 0;
        int ans  = 0;
        for(int i=0 ; i<n; i++){
            mp[fruits[i]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            
            ans = max(ans, i - left +1);



        }
        return ans;

        

        
    }
};