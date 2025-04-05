class Solution {
private:
    int XORSum(vector<int> &nums, int index, int currXOR){
        // return current XOR when all elements in nums are
        // already considered
        if(index == nums.size()){
            return currXOR;
        }

        // calculate the sum of subset xor with current element
        int withElement = XORSum(nums, index+1, currXOR ^ nums[index]);
        
        // then the sun of subset xor wihout current element
        int withoutElement = XORSum(nums, index+1, currXOR);

        return withElement + withoutElement;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0);
    }
};