class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";

        for(int i=1 ; i<n && k > ans.size() ; i++){
            ans += "1";

            string temp = ans;

            for(int j=temp.size()-2 ; j>=0 ; j--){
                char invertedBit = (temp[j] == '0') ? '1' : '0';
                ans += invertedBit;
            }
        }

        return ans[k-1];
        
    }
};