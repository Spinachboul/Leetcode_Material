class Solution {
public:
// concept: if at any point, n%3==2, then it is not possible to represent n as sum of powers of 3
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3==2) return false;
            n /= 3;
        }
        return true;
    }
};
