class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int count = 0;
        int mn = INT_MAX;

        for(auto& row: matrix){
            for(int x : row){
                if(x < 0) count++;
                sum += llabs(x);
                mn = min(mn, abs(x));
            }
        }

        if(count % 2 == 1){
            sum -= 2 * mn;
        }
        return sum;






        
    }
};