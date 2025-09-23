class Solution {
private:
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(s=="" || s==" ") return 1;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                string sub = s.substr(i, j-i+1);
                if(isPalindrome(sub)) count++;
            }
        }
        return count;

        
    }
};