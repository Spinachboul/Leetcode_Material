class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        bool res;
        while (i < bits.size()){
            if(bits[i] == 0){
                i += 1;
                res = true;
            }
            else{
                i += 2;
                res = false;
            }
            
        }
        return res;

    }
};