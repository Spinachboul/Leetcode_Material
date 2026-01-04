class Solution {
private:
    pair<int, int> numOfDivisors(int n){
        int count = 0;
        int sum = 0;
        for(int i=1; i * i <=n ; i++){
            if(n % i == 0){
                int d1 = i;
                int d2 = n/i;
                count++;
                sum += d1;
                if(d1 != d2){
                    count++;
                    sum += d2;
                }
                if(count > 4) return {0, 0};
            }
        }
        return {sum, count};
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=0 ; i<n ; i++){
            auto [sum, count] = numOfDivisors(nums[i]);
            if(count == 4){
                ans += sum;
            }
        }
        return ans;
        
    }
};