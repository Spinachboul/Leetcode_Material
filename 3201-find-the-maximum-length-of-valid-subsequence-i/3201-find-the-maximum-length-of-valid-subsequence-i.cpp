class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int oddCount = 0, evenCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                oddCount++;
            } else {
                evenCount++;
            }
        }

        if (evenCount == 0 || oddCount == 0) {
            return n;
        }

        if (evenCount > oddCount) {
            swap(evenCount, oddCount);
        }

        int ans = 0;

        if (evenCount == oddCount) {
            ans = evenCount + oddCount;
            return ans;
        }

        if (oddCount - evenCount == 1) {
            ans = evenCount + oddCount -1;
            return ans;
        }

        if (oddCount - evenCount > 1) {
            return 2 * evenCount + 1;
        }

        return ans;
    }
};