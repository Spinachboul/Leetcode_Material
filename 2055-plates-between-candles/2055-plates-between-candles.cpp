class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size(); 
        vector<int> prefix(n, 0);
        vector<int> left(n, -1), right(n, -1);

        // Build prefix sum of plates
        for(int i = 0; i < n; i++) {
            if(i > 0) prefix[i] = prefix[i - 1];
            if(s[i] == '*') prefix[i]++;
        }

        // Nearest candle to the left
        int lastCandle = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '|') lastCandle = i;
            left[i] = lastCandle;
        }

        // Nearest candle to the right
        lastCandle = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '|') lastCandle = i;
            right[i] = lastCandle;
        }

        // Answer queries
        vector<int> res;
        for(auto& it : queries) {
            int l = right[it[0]];  // nearest candle to the right of left bound
            int r = left[it[1]];   // nearest candle to the left of right bound
            if(l == -1 || r == -1 || l >= r) {
                res.push_back(0);
            } else {
                res.push_back(prefix[r] - prefix[l]);
            }
        }

        return res;
    }
};
