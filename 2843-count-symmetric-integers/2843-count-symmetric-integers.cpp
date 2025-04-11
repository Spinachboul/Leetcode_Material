class Solution {
private:
    bool isSymmetric(int x){
        string s = to_string(x);
        int n = s.size();
        if(n % 2 == 1) return false;
        int half = n/2;
        int sum1 =0, sum2 = 0;
        for(int i=0 ; i<half ; i++){
            sum1 += s[i] - '0';
        }
        for(int i=half ; i<n ; i++){
            sum2 += s[i] - '0';
        }
        return sum1==sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low ; i<=high ; i++){
            count += isSymmetric(i) ? 1 : 0;
        }
        return count;
        
    }
};