class Solution {
public:
    bool fun(vector<int> &freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0, right = 0;
        vector<int> freq(3, 0);
        int ans = 0;
        while(right < n){
            char curr = s[right];
            freq[curr - 'a']++;

            // while we have all the letters
            while(fun(freq)){
                ans += n - right;

                // remove the left most character
                char leftc = s[left];
                freq[leftc-'a']--;
                left++;
            }
            right++;
        }
        return ans;
        
    }
};