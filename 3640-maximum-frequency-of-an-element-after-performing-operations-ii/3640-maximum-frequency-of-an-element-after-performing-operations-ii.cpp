class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> numCount;
        set<int> modes;

        auto addMode = [&](int value){
            modes.insert(value);

            if(value - k >= nums.front()){
                modes.insert(value - k);
            }
            if(value + k <= nums.back()){
                modes.insert(value+k);
            }
        };


        int lastIndex = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != nums[lastIndex]){
                numCount[nums[lastIndex]] = i - lastIndex;
                ans = max(ans, i - lastIndex);
                addMode(nums[lastIndex]);
                lastIndex = i; 
            }
        }

        numCount[nums[lastIndex]] = (int)nums.size() - lastIndex;
        ans = max(ans, (int)nums.size() - lastIndex);
        addMode(nums[lastIndex]);

        auto leftBound = [&](int value){
            int left = 0, right = nums.size()-1;
            while(left < right){
                int mid = (left + right)/2;
                if(nums[mid] < value){
                    left = mid+1;
                }
                else right = mid;
            }
            return left;
        };

        auto rightBound = [&](int value){
            int left = 0, right = nums.size()-1;
            while(left < right){
                int mid = (left + right + 1)/2;
                if(nums[mid] > value){
                    right = mid-1;
                }
                else left = mid;
            }
            return left;
        };



        for(int mode: modes){
            int l = leftBound(mode-k);
            int r = rightBound(mode+k);

            int tempAns;
            if(numCount.count(mode)){
                tempAns = min(r-l+1, numOperations + numCount[mode]);

            }
            else{
                tempAns = min(r-l+1, numOperations);
            }
            ans = max(ans, tempAns);
        }
        return ans;

        
    }
};