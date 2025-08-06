class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int total = 0;

        auto ss = [](const vector<int> &a, const vector<int> &b){
            return a[1] > b[1];
        };

        sort(boxTypes.begin() , boxTypes.end(), ss);
        for(auto& it: boxTypes){
            int boxes = min(it[0], truckSize);
            total += boxes * it[1];
            truckSize -= boxes;
            if(truckSize == 0) break;
        }
        return total;
        
    }
};