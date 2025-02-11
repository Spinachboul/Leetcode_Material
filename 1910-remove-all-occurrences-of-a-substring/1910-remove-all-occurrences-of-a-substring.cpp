class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!= string::npos){
            int partStarts = s.find(part);

            s = s.substr(0 , partStarts) + s.substr(partStarts + part.size());
        }
        return s;
        
    }
};