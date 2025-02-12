class Solution {
private:
    int digitSum(int a){
        int sum = 0;
        while(a>0){
            int d = a%10;
            sum += d;
            a/=10;
        }
        return sum;

    }
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<pair<int,int>> mp;
        for(int i=0 ; i<n ; i++){
            int sumd = digitSum(nums[i]);
            mp.push_back({sumd , nums[i]});
        }
        sort(mp.begin() , mp.end());
        int mx = -1;

        for(int i=1 ; i<mp.size() ; i++){
            int curr = mp[i].first;
            int prev = mp[i-1].first;
            if(curr == prev){
                int currSum = mp[i].second + mp[i-1].second;
                mx = max(mx , currSum);
            }
        }
        return mx;




        
    }
};