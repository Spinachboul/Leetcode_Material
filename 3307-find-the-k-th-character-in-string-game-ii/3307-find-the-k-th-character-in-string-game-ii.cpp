class Solution {
private:
    char next(char c){
        int next = (c - 'a' + 1) % 26;
        return (char) (next + 'a');
    }

    int gl(long long num){
        long p = 1;
        int x = 0;
        while(p * 2 < num){
            p *= 2;
            x++;
        }
        return x;
    }
    char solve(long long k, vector<int>& op){
        if(k==1) return 'a';

        // get the lower power of 2 such that 2 * l < k
        int l = gl(k);

        long long p = ((long)1<<l);
        // if the operation is 0 at index l, next char is taken same
        // from the last string
        if(op[l] == 0){
            return solve(k-p, op);
        }
        return next(solve(k-p, op));
    }
public:
    char kthCharacter(long long k, vector<int>& operations) {
        return solve(k, operations);
        
    }
};