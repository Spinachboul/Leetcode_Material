class Solution {
public:
    int countValid(vector<int> &nums, int threshhold){
        int index = 0, count = 0;
        while(index < nums.size() -1){
            if(nums[index+1] - nums[index] <= threshhold){
                count++;
                index++;
            }
            index++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n= nums.size();
        sort(nums.begin() , nums.end());
        // 1,2,3,4,5,10,10

        // we apply binary search here
        int left = 0, right = nums[n-1]-nums[0];
        while(left < right){
            int mid = left + (right - left)/2;
            // if we have enough pairs, 
            if(countValid(nums, mid)>=p){
                right = mid;
            }
            else left = mid+1;
        }
        return left;

        
    }
};