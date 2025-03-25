class Solution {
private:
    bool checkCuts(vector<vector<int>> &rectangles, int dim){
        int count = 0;
        
        // sort the rectangle by their start coordinate in the given dimension
        sort(rectangles.begin() , rectangles.end(), [dim](const vector<int> &a, const vector<int> &b){
            return a[dim] < b[dim];

        });

        // track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim+2];
        for(int i=1 ; i<rectangles.size() ; i++){
            vector<int> rect = rectangles[i];

            // if the current rectangle starts after the furthest end we have seen , we found a gap where a cut can be made
            if(furthestEnd <= rect[dim]){
                count++;
            }

            // update the furthest ending
            furthestEnd = max(furthestEnd, rect[dim+2]);

            
        }
        return count >= 2;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        return checkCuts(rectangles, 0) || checkCuts(rectangles,1);


    }
};