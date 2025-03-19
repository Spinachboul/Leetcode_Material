class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int> flips;
        int count = 0;

        for(int i=0; i<nums.size() ; i++){
            while(!flips.empty() && i > flips.front() + 2){
                flips.pop_front();
            }

            if((nums[i] + flips.size()) % 2 == 0){
                if(i +2 >= nums.size()) return -1;
                count++;
                flips.push_back(i);
            }
        }
        return count;

        
    }
};