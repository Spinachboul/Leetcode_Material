class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        vector<int> precompute(10);
        int n = s.size();

        // precompute min additions steps for each digit
        for(int i=0 ; i<10 ; i++){
            int minVal = i, minStep = 0;
            for(int j=1 ; j<10 ; j++){
                int newVal = (i + a * j) % 10;
                if(newVal < minVal){
                    minVal = newVal;
                    minStep = j;
                }
            }
            precompute[i] = minStep;
        }

        // determine the reachable cycle positions reachable by repeatedly rotating by b
        vector<int> vis(n);
        int index = 0;
        while(!vis[index]){
            vis[index] = 1;
            index = (index + b) % n;
        }


        string ans = s;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                continue;
            }

            string rot = s;
            // for every rotation
            rotate(rot.begin() , rot.begin() + i, rot.end());

            // count how many times to add on odd/even positions
            vector<int> addCount = {(b%2) ? precompute[rot[0]-'0']  : 0 , precompute[rot[1]-'0'] };

            for(int j=0 ; j<n ; j++){
                int digit = rot[j] - '0';

                digit = (digit + addCount[j%2] * a) % 10;

                rot[j] = static_cast<char>('0' + digit);
            }
            ans = min(ans, rot);


        }
        return ans;


        
    }
};