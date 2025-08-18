class Solution{
    // define a global variabe heree
    const double EPS = 1e-6;


    // now we create some public methods here
    public:
    bool judgePoint24(vector<int> &cards){
        vector<double> nums;
        for(int i=0; i<cards.size() ;  i++){
            double x = (double)cards[i];
            nums.push_back(x);
        }
        return recurse(nums);
    }

    // now we create some private methods
    private:
    bool recurse(vector<double> &nums){
        // for every recursion, we will apply the base case
        if(nums.size() == 1){
            return fabs(nums[0] - 24.0) < EPS;
        }
        int n = nums.size();


        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == j) continue;

                vector<double> next;

                for(int k=0 ; k<n ; k++){
                    if(k != i && k != j) next.push_back(nums[k]);
                }

                for(double x : compute(nums[i] , nums[j])){
                    next.push_back(x);
                    // if we meet the base condition
                    if(recurse(next)) return true;
                    // else we need to backtrack and then look for other possible combinations
                    next.pop_back();
                }
            }
        }

        // if no combination works, we will simplu return false;
        return false;
    }


    unordered_set<double> compute(double a, double b){
        unordered_set<double> ans;
        ans.insert(a + b);
        ans.insert(a-b);
        ans.insert(b-a);
        ans.insert(a *b);
        if(fabs(a) > EPS) ans.insert(a / b);
        if(fabs(b) > EPS) ans.insert(b / a);
        return ans;
    }
};