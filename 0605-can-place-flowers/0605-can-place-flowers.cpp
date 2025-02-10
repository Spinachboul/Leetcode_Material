class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int nn = flowerbed.size();

        int count = 0;
        for(int i=0 ; i<nn ; i++){
            if(i < nn-1 && i>0){
                if(flowerbed[i] == 0){
                    if(flowerbed[i+1] ==0 && flowerbed[i-1]==0){
                        flowerbed[i] = 1;
                        count++;

                    }
                }
            }

        }
        return count >= n;

        
    }
};