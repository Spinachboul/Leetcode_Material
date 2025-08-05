class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, res = 0;
        int n = nums.size();

        while (right < n) {
            if (nums[right] % 2 == 1) {
                count++;
            }

            while (count > k) {
                if (nums[left] % 2 == 1) {
                    count--;
                }
                left++;
            }

            res += (right - left + 1);
            right++;
        }

        return res;
    }
};
