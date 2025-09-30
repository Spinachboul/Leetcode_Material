class NumArray {
private:
    int n;
    vector<int> nums, bit;

    void add(int i, int delta){
        while(i <= n){
            bit[i] += delta;
            i += i & -i;
        }



    }

    int getSum(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }


public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        bit.assign(n+1, 0);

        // build the BIT
        for(int  i=0 ; i<n ; i++){
            add(i+1, nums[i]);
        }

        
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index + 1 , delta);
        
    }
    
    int sumRange(int left, int right) {
        return getSum(right+1) - getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */