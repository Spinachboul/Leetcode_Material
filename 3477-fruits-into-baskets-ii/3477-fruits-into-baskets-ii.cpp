class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        for(auto& it : fruits){
            int unplaced = 1;
            for(int i=0 ; i<n ; i++){
                if(it <= baskets[i]){
                    baskets[i] = 0;
                    unplaced = 0;
                    break;
                }
            }
            count += unplaced;
        }
        return count;
        
        
    }
};