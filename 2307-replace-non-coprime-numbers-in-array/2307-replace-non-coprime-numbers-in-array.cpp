class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int x : nums){
            st.push_back(x);
            while(st.size() > 1){
                int x = st[st.size()-2];
                int y = st[st.size()-1];
                int g = gcd(x, y);
                if(g == 1) break;

                long long l= (1LL * x/g) * y;
                st.pop_back();
                st.back() = (int)l; 
            }
        }
        return st;
        
    }
};