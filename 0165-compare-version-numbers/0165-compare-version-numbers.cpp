class Solution {
public:
    // convert string to integer
    int conv(string s){
        int ans = 0;

        // "110" - 110
        for(int i=0 ; i<s.size() ; i++){
            // this will get us the first '1'
            int num = s[i] - '0';

            // then ans becomes "10" (quotes represent the current state of the number, not the literal string)
            ans *= 10;

            // then the ans becomes "11"
            ans += num;
        }

        // and lastly we will simply return the ans;
        return ans;
    }


    vector<int> solve(string s){

        // we add adot to simpy mark the ending of the current string so that we can know
        // when the next part starts.
        s += ".";

        int n = s.size();

        // we first convert the whole string to the ans vector devoid of all the dots
        vector<int> ans;

        // the current string we are workin upon
        string str = "";

        for(int i=0 ; i<n ; i++){
            if(s[i] == '.'){
                // push the current number back to the ans vector
                int num = conv(str);

                ans.push_back(num);
                
                // and then again reset the string to form the next number after the dot
                // which is in the else condition
                str = "";
            }
            else{
                str += s[i];
            }
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        
        // first we get botrh both the vector version of the 2 strings
        vector<int> v1 = solve(version1);
        vector<int> v2 = solve(version2);

        int n = v1.size();
        int m = v2.size();

        // then we simply add the 0s to the smaller vector in size, since we want to make both of them as equal
        if(n < m){
            for(int i=0  ; i<(m-n) ; i++) v1.push_back(0);
        }
        else{
            for(int i=0 ; i<(n-m) ; i++) v2.push_back(0);
        }
        int sz = v1.size();
        
        // we then compare the 2 vectors element by element and return the values according to the question
        for(int i=0 ; i< sz ;  i++){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }

        return 0;
    }
};