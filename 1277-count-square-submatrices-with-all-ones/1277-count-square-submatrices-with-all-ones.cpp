class Solution {
private:
    bool valid(vector<vector<int>> &v, int i, int j,int k){
        for(int x=0 ; x < k ; x++){
            for(int y=0 ; y<k ; y++){
                if(v[i + x][j + y] == 0) return false;
            }
        }
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int k=1 ; k<=min(m, n) ; k++){
            for(int i=0 ; i<m-k+1 ; i++){
                for(int j=0 ; j<n-k+1 ; j++){
                    // now we need to condition on this submatrix
                    if(valid(matrix, i, j, k))count++;
                }
            }

        }
        return count;

        

        
        
    }
};