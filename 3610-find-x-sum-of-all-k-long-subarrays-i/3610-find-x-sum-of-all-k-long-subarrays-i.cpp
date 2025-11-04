class Solution {
private:
    unordered_map<int, int> countFreq(vector<int> &nums, int start, int end){
        unordered_map<int, int> mp;
        for(int i=start ; i<=end ; i++){
            mp[nums[i]]++;
        }
        return mp;
    }

    int getXSum(unordered_map<int, int> &mp, int x){
        vector<pair<int, int>> arr(mp.begin() , mp.end());

        sort(arr.begin() , arr.end(), [&](auto& a, auto& b){
            if(a.second == b.second) return a > b;
            return a.second > b.second;

        });
        int count = 0;
        int sum = 0;
        for(auto& [num, cnt]: arr){
            sum += num * cnt;
            if(++count == x) break;
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0 ; i+k <= n; i++){
            auto freq = countFreq(nums, i, i+k-1);
            int sum = getXSum(freq, x);
            ans.push_back(sum);
        }

        return ans;


        
    }
};