class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // sliding window approach
        int n = blocks.size();
        int left = 0;
        int ans = INT_MAX;
        int whites = 0;

        for(int right = 0; right < n ; right++){
            if(blocks[right] == 'W'){
                whites++;
            }

            if(right - left + 1 == k){
                ans = min(ans, whites);
                if(blocks[left] == 'W') whites--;
                left++;
            }

        }
        return ans;

        
    }
};