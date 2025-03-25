class Solution {
public:
    bool isMatch(string text, string pattern) {
        if(pattern.empty()) return text.empty();

        bool first_match = (!text.empty() && (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.size() >= 2 && pattern[1] == '*') {
            return (isMatch(text, pattern.substr(2)) || 
                    (first_match && isMatch(text.substr(1), pattern)));
        } else {
            return first_match && isMatch(text.substr(1), pattern.substr(1));
        }
        
    }
};