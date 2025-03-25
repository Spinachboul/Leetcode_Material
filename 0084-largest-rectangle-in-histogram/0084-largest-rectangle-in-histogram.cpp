class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for(int i=0; i<heights.size() ; i++){
            while(st.top() != -1 && heights[i] <= heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = abs(i - st.top() - 1);
                ans = max(ans, width * height);

            }
            st.push(i);
        }

        while(st.top() != -1){
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() -1;
            ans = max(ans, width * height);
        }
        return ans;
        
    }
};