class Solution {
public:
    int f(vector<int> &nums, long long x1, long long v){
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(x1 >= 0 && nums[mid] * x1 <= v || x1 <0 && nums[mid] * x1 > v){
                left = mid+1;
            }
            else right = mid-1;
        }
        if(x1 >= 0) return left;
        else return n - left;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        long long left = -1e10;
        long long right = 1e10;
        while(left <= right){
            long long mid = left + (right-left)/2;
            long long count = 0;
            for(int i=0 ; i<n ; i++){
                count += f(nums2, nums1[i], mid);

            }
            if(count < k){
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return left;

    }
};