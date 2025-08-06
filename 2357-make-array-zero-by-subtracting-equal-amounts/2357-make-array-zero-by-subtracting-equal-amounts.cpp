class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        for(int it : nums){
            if(it != 0){
                st.insert(it);
            }
        }
        return st.size();
        
    }
};