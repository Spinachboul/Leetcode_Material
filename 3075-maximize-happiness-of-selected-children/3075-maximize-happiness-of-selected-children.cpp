class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end(), greater<>());
        long long n = happiness.size();
        long long total = 0;
        int turns = 0;
        for(int i=0 ; i<k ; i++){
            total += max(happiness[i] - turns, 0);
            turns++;
        }
        return total;
        
    }
};