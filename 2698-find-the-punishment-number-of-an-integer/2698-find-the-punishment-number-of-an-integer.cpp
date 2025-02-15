# define vvi vector<vector<int>>
class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            int squareNum = i*i;
            string num = to_string(squareNum);

            // initialize the values in the memo array
            vector<vector<int>> memo(num.size(), vector<int>(i+1, -1));

            // if there is valid partition and if yes, then we need to add the squared number
            if(findPartition(0, 0, num, i, memo)){
                ans += squareNum;
            }
        }
        return ans;
        
    }
    private:
    bool findPartition(int index, int sum, string num, int target, vvi &memo){
        if(index == num.size()) return sum==target;

        // invalid partition since the sum is greater than the number
        if(sum > target) return false;

        // if the res of this state is already calculated, just return it
        if(memo[index][sum] != -1) return memo[index][sum];

        bool found = false;

        for(int i=index ; i<num.size() ; i++){
            // create a partition
            string currStr = num.substr(index, i-index+1);
            // convert this partition into a number
            int currNum = stoi(currStr);

            //check recursively if valid partition is found
            found = found || findPartition(i+1, sum + currNum , num, target, memo);
            if(found==true) return true;
        }

        return memo[index][sum] = found;


    }
};