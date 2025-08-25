class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        if(mat.empty() || mat[0].empty()) return {};
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans, inter;

        for(int i=0 ; i<n+m-1 ; i++){
            inter.clear();
            int r = (i < m) ? 0 : i-m+1;
            int c = (i < m) ? i : m-1;

            while(r < n && c > -1){
                inter.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(i % 2 == 0){
                reverse(inter.begin() , inter.end());
                
            }
            
            ans.insert(ans.end() , inter.begin() , inter.end());
                

        }
        return ans;

        
        
    }
};