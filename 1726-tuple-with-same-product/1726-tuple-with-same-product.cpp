# define all(a) a.begin(),a.end()
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(all(nums));
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=nums.size()-1 ; j>=i+1 ; j--){
                int prod = nums[i] * nums[j];
                unordered_set<int> possibleD;

                // for all values of c
                for(int k=i+1 ; k<j ; k++){
                    int c = nums[k];
                    if(prod % c == 0){
                        int dval = prod / c;
                        if(possibleD.find(dval) != possibleD.end()){
                            ans += 8;

                        }
                        possibleD.insert(c);

                    }
                }
            }
        }
        return ans;
    }
};