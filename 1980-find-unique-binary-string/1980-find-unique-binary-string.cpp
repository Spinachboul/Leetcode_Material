class Solution {
vector<string> mp;
// private:
//     void generate(int n, int index, string current){
//         if(index == n){
//             mp.push_back(current);
//             return;
//         }

//         generate(n, index+1, current + "0");
//         generate(n, index+1, current + "1");
//     }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> ints;
        for(auto& it: nums){
            ints.insert(stoi(it, 0, 2));
        }

        for(int i=0 ; i<=nums.size() ; i++){
            if(ints.find(i) == ints.end()){
                string ans = bitset<16>(i).to_string();
                return ans.substr(16-nums.size());
            }
        }
        return "";

    }
};