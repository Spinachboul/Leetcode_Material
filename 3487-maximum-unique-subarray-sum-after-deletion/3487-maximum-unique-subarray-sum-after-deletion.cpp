class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto& it : nums){
            if(it > 0){
                st.emplace(it);
            }
        }
        if(st.empty()){
            int ans = *max_element(nums.begin() , nums.end());
            return ans;
        }

        int sum = 0;
        while(!st.empty()){
            int element = *st.begin();
            sum += element;
            st.erase(element);
        
        }
        return sum;
        
    }
};