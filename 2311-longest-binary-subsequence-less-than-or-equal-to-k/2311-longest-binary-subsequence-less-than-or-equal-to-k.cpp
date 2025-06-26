class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sum = 0;
        int count = 0;
        int bits = 32 - __builtin_clz(k);
        for(int i=0 ; i<s.size() ; i++){
            char ch = s[s.size()-1-i];
            if(ch == '1'){
                if(i < bits && sum + (1 << i) <= k){
                    sum += 1 << i;
                    count++;
                }
            }
            else{
                count++;

            }
        }
        return count;

        
    }
};