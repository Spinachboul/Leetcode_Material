class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        int curr = 0;
        while(curr < n){
            res.push_back(s.substr(curr, k));
            curr+=k;
        }

        res.back() += string(k-res.back().length(), fill);
        // string(length, char)
        return res;
        
    }
};