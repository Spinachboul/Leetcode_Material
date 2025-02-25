#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    const int mod = 1e9+7;

private:
    bool isOddNumberofOdd(vector<int> &v){
        int count = 0;
        for(int num : v){
            if(num % 2) count++;
        }
        return (count % 2) == 1;
    }

public:
    int numOfSubarrays(vector<int>& arr) {
        ll count = 0;
        int n = arr.size();
        
        for(int left = 0; left < n; left++) {
            for(int right = left; right < n; right++) {
                vector<int> subarr(arr.begin() + left, arr.begin() + right + 1);
                if(isOddNumberofOdd(subarr)){
                    count = (count + 1) % mod;
                }
            }
        }

        return count;
    }
};
