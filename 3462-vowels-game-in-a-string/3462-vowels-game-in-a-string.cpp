class Solution {
private:
    int countVowels(string &s){
        int count = 0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }
        return count;
    }
public:

    bool doesAliceWin(string s) {
        int count = countVowels(s);
        if(count == 0) return false;
        else return true;

        
    }
};