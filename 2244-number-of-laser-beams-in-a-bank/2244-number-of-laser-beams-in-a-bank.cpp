class Solution {
private:
int Ones(const string &arr){
    int count = 0;
    for(int i=0 ; i<arr.size(); i++){
        if(arr[i] == '1'){
            count++;
        }
    }
    return count;
}
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount = 0;
        int total = 0;
        for(auto& row : bank){
            int currRow = Ones(row);
            if(currRow == 0){
                continue;
            }

            if(prevCount > 0){
                total += prevCount * currRow;
            }

            prevCount = currRow;

        }
        return total;

        
    }
};