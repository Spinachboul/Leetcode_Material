class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left  = 0, right = 0;
        int total = 0;

        vector<int> freq(3, 0);

        while(right < n){
            char curr = s[right];
            freq[curr - 'a']++;

            while(hasAllChars(freq)){
                total += n - right;

                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }
            right++;
        }
        return total;

        
    }
private:
    bool hasAllChars(vector<int> &freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
};