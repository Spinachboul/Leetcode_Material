class Solution {
vector<string> mp;
private:
    void generate(int n, int index, string current){
        if(index == n){
            mp.push_back(current);
            return;
        }

        generate(n, index+1, current + "0");
        generate(n, index+1, current + "1");
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st (nums.begin() , nums.end());
        generate(nums.size(), 0, "");
        for(int i=0 ; i<(int)mp.size() ; i++){
            if(st.find(mp[i]) == st.end()){
                return mp[i];
            }
        }
        return "-1";
    }
};