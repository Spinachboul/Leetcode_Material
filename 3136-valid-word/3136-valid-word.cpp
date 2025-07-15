class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool hasConsonant = true;
        bool hasVowel = true;
        for(auto& c: word){
            if(isalpha(c)){
                c = tolower(c);
                if(c == 'a' || c == 'e' || c == 'e' || c == 'o' || c == 'u'){
                    hasVowel = true;
                }
                else{
                    hasConsonant = true;
                }
            }
            else if(!isdigit(c)){
                return false;
            }
        }
        return hasVowel && hasConsonant;
        
    }
};