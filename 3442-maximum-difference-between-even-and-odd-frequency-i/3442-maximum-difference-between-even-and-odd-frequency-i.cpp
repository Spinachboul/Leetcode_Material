class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> mp;
        for(int i=0 ; i<s.size() ; i++){
            mp[s[i]]++;
        }
        int mxOdd = 1, mnEven = s.size();
        for(auto& [value, f]: mp){
            if(f%2==1){
                mxOdd = max(mxOdd, f);
            }
            else mnEven = min(mnEven, f);
        }
        return mxOdd - mnEven;


        

        
    }
};