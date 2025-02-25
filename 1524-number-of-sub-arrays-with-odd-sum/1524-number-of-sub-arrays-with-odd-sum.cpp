#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    const int mod = 1e9+7;

// private:
//     bool isOddNumberofOdd(vector<int> &v){
//         int count = 0;
//         for(int num : v){
//             if(num % 2) count++;
//         }
//         return (count % 2) == 1;
//     }

public:
    int numOfSubarrays(vector<int>& arr) {
        ll count = 0;
        int n = arr.size();
        int odd = 0, even = 1;
        ll prefixSum = 0;
        for(auto& it: arr){
            prefixSum += it;
            if(prefixSum % 2 == 0){
                count  = (count + odd) % mod;
                even++;
            }
            else{
                count = (count + even) % mod;
                odd++;
            }
        }
        
        return count;
    }
};
