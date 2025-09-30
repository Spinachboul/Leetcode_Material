class NumArray {
private:
    int n;
    vector<int> nums;   // keep original array values
    vector<int> bit;    // Fenwick Tree (1-indexed)

    void add(int i, int delta) {
        // i is 1-indexed inside BIT
        while (i <= n) {
            bit[i] += delta;
            i += i & -i; // move to parent
        }
    }

    int prefixSum(int i) {
        // sum of first i elements (nums[0..i-1])
        int total = 0;
        while (i > 0) {
            total += bit[i];
            i -= i & -i; // move to previous node
        }
        return total;
    }

public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        bit.assign(n + 1, 0);

        // build the BIT
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index + 1, delta); // BIT is 1-indexed
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};
