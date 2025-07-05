class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int mx = -1;
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }
        for(auto& [num, val] : mp){
            if(num == val){
                mx = max(mx, num);
            }
        }
        return mx;
        
    }
};