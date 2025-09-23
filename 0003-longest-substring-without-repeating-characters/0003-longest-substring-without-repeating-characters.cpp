class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int n = s.size();
        int ans = 0;
        int st = 0;

        for(int i=0 ; i<n ; i++){
            if(seen[s[i]] >= st){
                st  = seen[s[i]] + 1;
            }
            seen[s[i]] = i;
            ans = max(ans, i - st + 1);
        }
        return ans;
        
    }
};