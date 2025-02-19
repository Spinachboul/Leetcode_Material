class Solution {
private:
    void generateAllHappy(int n, int k, string current, string &res, int &index){
        if(n == (int)current.size()){
            index++;
            if(index == k){
                res = current;
                return;
            }
            return;  // Don't forget to return here
        }

        for(char ch = 'a' ; ch <= 'c' ; ch++){
            if(!current.empty() && current.back() == ch) continue;
            generateAllHappy(n , k, current + ch, res, index);
            if(!res.empty()) return; // if we get a result
        }
    }

public:
    string getHappyString(int n, int k) {
        string res = "";
        int index = 0;
        generateAllHappy(n, k, "", res, index);
        return res;
    }
};
