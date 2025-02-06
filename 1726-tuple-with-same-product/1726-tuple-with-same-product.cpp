# define all(a) a.begin(),a.end()
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int prod = nums[i] * nums[j];
                mp[prod]++;
            }
        }

        for(auto& [val, count] : mp){
            int equal = count * (count-1) / 2;
            ans += 8 * equal;
        }
        return ans;
    }

};