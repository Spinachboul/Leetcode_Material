#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c=='A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') // handle uppercase too
            return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowels;

        for(int i=0 ; i<s.size() ; i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin() , vowels.end());

        // reverse(vowels.begin() , vowels.end());

        int j=0;
        for(int i=0 ; i<s.size(); i++){
            if(isVowel(s[i])){
                s[i] = vowels[j++];
            }
        }

        return s;
    }
};
