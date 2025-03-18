class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = nums.size();
        int res = 1;

        while(left <= right){
            int len = left + (right - left)/2;
            if(canForm(len, nums)){
                res = len;
                left = len +1;
            }else{
                right = len-1;
            }
        }
        return res;

        
    }
private:
    bool canForm(int len, vector<int>& nums){
        if(len <= 1){
            return true;
        }

        for(int start = 0 ; start <= nums.size()- len ; ++start){
            int bitMask = 0;
            bool isNice = true;

            for(int pos = start ; pos < start + len  ; ++pos){
                if((bitMask & nums[pos]) != 0){
                    isNice = false;
                    break;
                }
                bitMask |= nums[pos];
            }
            if(isNice) return true;
        }
        return false;
    }
};