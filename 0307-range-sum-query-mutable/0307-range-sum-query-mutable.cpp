class NumArray {
public:
    vector<int> arr, bit;
    NumArray(vector<int>& nums) {
        bit = vector<int>(nums.size() +1 , 0);
        arr = nums;

        for(int i=0; i<nums.size() ; i++){
            my_update(i, arr[i]);
        }
        
    }

    void my_update(int i, int x){
        i++;
        while(i<=arr.size()){
            bit[i] += x;
            i = i + (i & (-i));
        }
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        my_update(index , diff);
        
    }

    int query(int i){
        i = i + 1;
        int res = 0;
        while(i > 0){
            res += bit[i];
            i = i - (i & (-i));
        }
        return res;
    }
    
    int sumRange(int left, int right) {
        return query(right) - query(left-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */