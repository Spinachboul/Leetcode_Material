class Solution {
private:
    void generateAllHappy(int n, vector<string> &stt, string current){
        if(n == current.size()){
            stt.push_back(current);
            return;
        }

        for(char ch = 'a' ; ch <= 'c' ; ch++){
            // skip if curr[i] == curr[i+1]
            if(current.size() > 0 && ch == current.back()) continue;
            generateAllHappy(n, stt, current + ch);

        }

        
    }
public:
    string getHappyString(int n, int k) {
        vector<string> stt;
        // call the function
        generateAllHappy(n, stt, "");
        if(stt.size() < k) return "";
        return stt[k-1];


        
    }
};