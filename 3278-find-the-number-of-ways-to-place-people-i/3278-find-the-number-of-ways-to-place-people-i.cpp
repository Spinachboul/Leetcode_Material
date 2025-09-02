class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int count = 0;
        for(int i=0 ; i<n ; i++){
            auto& pa = points[i];
            for(int j=0 ; j<n ; j++){
                auto& pb = points[j];
                if(i==j || !(pa[0] <= pb[0] && pa[1] >= pb[1]))continue;

                if(n == 2){
                    count++;
                    continue;
                }
                bool illegal = false;

                for(int k=0 ; k<n ; k++){
                    if(k == i || k == j) continue;

                    auto& temp = points[k];

                    bool isContainedX = temp[0] >= pa[0] && temp[0] <= pb[0];
                    bool isContainedY = temp[1] <= pa[1] && temp[1] >= pb[1];
                    if(isContainedX && isContainedY){
                        illegal = true;
                        break;
                    }

                }
                if(!illegal){
                    count++;
                }
            }
        }
        return count;
        
        
    }
};