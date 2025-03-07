class Solution {
bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2 ; i*i <= n ; i++){
        if(n % i == 0) return false;
    }
    return true;
}
public:
    vector<int> closestPrimes(int left, int right) {
       int num1=-1, num2=-1;
       int minDiff = right; 
        vector<int> primes;
        for(int i=left ; i<=right ; i++){
            if(isPrime(i))primes.push_back(i);
        }

        if(primes.size() < 2) return {-1, -1};
        for(int i=1 ; i<primes.size() ; i++){
            int n1 = primes[i-1];
            int n2 = primes[i];
            int diff = n2 - n1;
            if(diff < minDiff){
                minDiff = diff;
                num1 = n1;
                num2 = n2;
            }
        }
        return {num1, num2};

        
    }
};