class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int mx = 0;
        int mxArea = 0;
        for(auto& it: dimensions){
            int l = it[0];
            int w = it[1];
            int diaS = l * l + w * w;
            int area = l * w;
            if(diaS > mx){
                mx = diaS;
                mxArea = area;
            }
            else if(diaS == mx){
                mxArea = max(mxArea, area);
            }

        }
        return mxArea;
        
    }
};