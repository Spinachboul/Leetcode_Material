# define vi vector<int>
# define pb push_back
class Solution {
public:
    string getPermutation(int n, int k) {
        /*
        The key idea is to directly jump on to the 
        kth factorial via the process of precomputation
        solution:
        https://leetcode.com/problems/permutation-sequence/solutions/6297853/permutation-sequence-c/?envType=problem-list-v2&envId=m3l4cclc&
        */
        int fact = 1;
        vi nums;
        for(int i=1 ; i<n ; i++){
            fact *= i;
            nums.pb(i);
        }
        nums.pb(n);
        k--;
        string ans = "";
        while(!nums.empty()){
            int ind = k / fact;
            ans += to_string(nums[ind]);
            nums.erase(nums.begin() + ind);
            if(nums.empty()) break;
            k %= fact;
            fact /= nums.size();
        }
        return ans;


        
    }
};