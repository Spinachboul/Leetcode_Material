class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,string s) {
       string st = to_string(start - 1);
       string e = to_string(finish);

       return calc(e, s, limit) - calc(st, s, limit);
    }

    long long calc(string x, string s, int limit){
        // base conditions
        if(x.size() < s.size()) return 0;
        if(x.size() == s.size()){
            return x>=s ? 1 : 0;
        }

        string suffix = x.substr(x.length() - s.length(), s.length());
        long long count = 0;
        int preLen = x.size() - s.size();
        for(int i=0 ; i< preLen ; i++){
            if(limit < (x[i] - '0')){
                count += (long) pow(limit+1, preLen-i);
                return count;
            }
            count += (long) (x[i] - '0') * (long) pow(limit +1 , preLen - 1 - i);
        }        
        if(suffix >= s){
            count++;
        }
        return count;
    }
};