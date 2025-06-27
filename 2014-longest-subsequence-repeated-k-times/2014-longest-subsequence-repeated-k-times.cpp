class Solution {
public:
    bool helper(string &s, int k, string &sub){
        int pos= 0, count=0;
        for(char c: s){
            if(c == sub[pos]){
                pos++;
                if(pos == sub.size()){
                    pos = 0;
                    count++;
                    if(count == k){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();

        vector<int> f(26);
        for(int i=0 ; i<s.size() ; i++){
            f[s[i] - 'a']++;
        }
        vector<char> cand;
        for(int i=25 ; i>=0 ; i--){
            if(f[i] >= k){
                cand.push_back('a' + i);
            }
        }
        queue<string> q;
        for(char c: cand){
            q.push(string(1, c));
        }

        string ans = "";
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr.size() > ans.size()){ // checking to get lexicographically maximum string
                ans = curr;
            }
            for(char ch : cand){
                string next = curr + ch;
                if(helper(s, k, next)){
                    q.push(next);
                }
            }
        }
        return ans;


    }
};