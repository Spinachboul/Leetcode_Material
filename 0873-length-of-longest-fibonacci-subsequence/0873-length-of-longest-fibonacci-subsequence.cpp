class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // we store the numbers in the hashmap for easy lookup
        unordered_set<int> st(arr.begin() , arr.end());
        int ans = 0;
        // try all possible first 2 numbers in the sequence
        for(int start = 0 ; start < n ; start++){
            for(int next = start+1; next < n ; next++){
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;

                while(st.find(curr) != st.end()){
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    ans = max(ans, ++len);
                }
            }
        }
        return ans;


        
    }
};