class Solution {
public:
    string change(int x, int y, int num){
        string nums = to_string(num);
        for(auto& it: nums){
            if(it-'0' == x){
                it = '0' + y;
            }
        }
        return nums;
    }
    int maxDiff(int num) {
        int mn = num, mx = num;
        for(int x=0 ; x<10 ; x++){
            for(int y=0 ; y<10 ; y++){
                string str = change(x, y, num);
                // check for any leading zeros
                if(str[0]!= '0'){
                    int n = stoi(str);
                    mx = max(mx, n);
                    mn = min(mn, n);
                }
            }
        }
        return mx - mn;

        
    }
};