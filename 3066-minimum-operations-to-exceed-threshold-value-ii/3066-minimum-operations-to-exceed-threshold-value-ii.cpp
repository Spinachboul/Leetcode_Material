# define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ll, vector<ll>, greater<ll>> pq (nums.begin() , nums.end());
        int operations = 0;
        while(pq.size() > 1 && pq.top() < k){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ll new_val = min(x, y) * 2 + y;
            pq.push(new_val);
            operations++;
        }
        return operations;


        

        
    }
};