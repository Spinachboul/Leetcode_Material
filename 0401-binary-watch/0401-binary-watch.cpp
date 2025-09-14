class Solution {
public:
    vector<string> readBinaryWatch(int total) {
        vector<string> ans;
        for(int i=0 ; i<12 ; i++){
            for(int j=0 ; j<60 ; j++){
                int x = __builtin_popcount(i);
                int y = __builtin_popcount(j);
                string temp = "";
                if(x + y == total){
                    temp += to_string(i) + ":";
                    if(j < 10){
                        temp += "0";
                    }
                    temp += to_string(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
    }
};