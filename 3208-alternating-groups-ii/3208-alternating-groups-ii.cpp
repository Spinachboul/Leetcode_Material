class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // expanding the array
        for(int i=0 ; i+1<k ; i++){
            colors.push_back(colors[i]);
        }

        int n = colors.size();
        int left = 0, right = 1;
        int ans = 0;

        while(right < n){
            if(colors[right] == colors[right-1]){
                left = right;
                right++;
            }
            else{
                right++;
            }
            if(right - left < k) continue;

            while(right - left + 1 > k){
                left++;
            }
            ans++;
            
        }

        return ans;

        
        
    }
};