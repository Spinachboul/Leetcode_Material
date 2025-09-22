class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>f(100, 0);
        for(int num : nums){
            f[num-1]++;
        }

        sort(f.begin() , f.end());

        int mx = f.size()-1;
        int total = f[mx];


        while(mx > 0 && f[mx] == f[mx-1]){
            total += f[mx];
            mx--;
        }
        return total;

    }
};