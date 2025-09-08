class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1 ; i<n ; i++){
            int j = n - i;
            string s1 = to_string(i);
            string s2 = to_string(j);
            string tot = s1 + s2;
            if(tot.find('0') == string::npos){
                return {i, j};
            }
            
        }
        return {};
        
    }
};