class Solution {
public:
    int bestClosingTime(string customers) {
        int n =  customers.size();
        
        int x=0, y=0,z=0;

        for(int i=0 ; i<n ; i++){
            if(customers[i] == 'Y') ++z;
            else --z;

            if (z > y){
                y = z;
                x = i + 1;
            }
        }
        return x;
        
    }
};