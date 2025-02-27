class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        // dp[prev][curr] stores the lenght of the Fibonacci Sequence ending at indexes prev, curr
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        unordered_map<int, int> mp; // for easy lookup of number index, to check if we can extend (means add 1 + currLen) for our Fibonacci Sequence
        for(int i=0 ; i<arr.size() ; i++){
            mp[arr[i]] = i;
        }

        for(int curr = 0 ; curr < arr.size() ; curr++){
            for(int prev = 0 ; prev < curr ; prev++){
                int diff = arr[curr] - arr[prev];
                int prevIdx = -1;
                if(mp.find(diff) != mp.end()){
                    prevIdx = mp[diff];
                }

                if(diff < arr[prev] && prevIdx != -1){
                    dp[curr][prev] = dp[prev][prevIdx] +1;
                }
                else{
                    dp[curr][prev] = 2; // this is the starting case
                    // btw we cant have any length as 2 for FS
                }
                ans = max(ans, dp[curr][prev]);
            }
        }
        return ans>2 ? ans : 0;
    }
};