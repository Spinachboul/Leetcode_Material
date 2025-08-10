class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin() , s.end());

        // precompute stored digit strings for all the power of 2 upto 10^9
        set<string> st;
        if(st.empty()){
            for(long long x= 1 ; x <1e9 ; x<<=1){
                string t = to_string(x);
                sort(t.begin() , t.end());
                st.insert(t);

            }
        }
        return st.count(s) > 0;

        
    }
};