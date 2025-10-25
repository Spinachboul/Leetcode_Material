class Solution {
public:
    int totalMoney(int n) {
        int k = n/7;
        int F = 28;
        int L = 28 + (k-1)*7;
        int aSum = k * (F + L)/2;



        int mon = 1 + k;
        int fin = 0;
        for(int i=0 ; i<n%7 ; i++){
            fin += mon + i;
        }
        return aSum + fin;
    }
};