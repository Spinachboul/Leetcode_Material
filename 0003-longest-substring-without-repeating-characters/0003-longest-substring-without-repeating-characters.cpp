class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seem(256, -1);

        int n = s.size();
        int ans = 0;
        int ss = 0;
        for(int i=0 ; i<n ; i++){
            if(seem[s[i]] >= ss){
                ss = seem[s[i]] + 1;
            }
            seem[s[i]] = i;
            ans = max(ans,  i - ss + 1);
        }
        return ans;
        
    }
};