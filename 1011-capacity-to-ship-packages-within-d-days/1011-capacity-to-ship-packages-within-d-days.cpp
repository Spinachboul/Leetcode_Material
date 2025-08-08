class Solution {
public:
    bool check(int mid, vector<int>& w, int days){
        int m = mid;
        int n = w.size();
        int count = 1;
        for(int i=0 ; i<n ; i++){
            if(m >= w[i]){
                m -= w[i];
            }
            else{
                count++;
                m = mid;
                m -= w[i];
            }
        }
        if(count > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max = INT_MIN;
        int sum  = 0;
        int n = weights.size();
        for(int i=0 ; i<n ; i++){
            sum += weights[i];
            if(weights[i] > max) max = weights[i];
        }

        int low = max;
        int high = sum;
        int min = sum;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, weights, days)){
                min = mid;
                high = mid-1;
            }
            else low = mid +1;
        }
        return min;



        
    }
};