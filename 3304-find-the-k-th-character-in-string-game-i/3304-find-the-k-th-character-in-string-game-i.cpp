class Solution {
public:
    char kthCharacter(int k) {
        int steps = 0;
        int original = k;
        while(k >1 ){
            int power = 1;
            while(power * 2 < k) power *= 2;
            k -= power;
            steps += 1;

        }
        char ans = (char)((('a' - 'a') + steps) % 26 + 'a');
        return ans; 
        
    }
};