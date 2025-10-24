class Solution {
public:
void nextPermutation(string& s){
    int size = s.size();
    int pos = size - 2;
    while(pos >= 0 && s[pos] >= s[pos+1]){
        --pos;
    }

    if(pos==-1){
        reverse(s.begin() , s.end());
        return;
    }

    int j = size - 1;
    while(s[pos] >= s[j]){
        --j;
    }
    swap(s[pos] , s[j]);
    reverse(s.begin() + pos + 1, s.end());
}

    int nextBeautifulNumber(int n) {
        set<int> st;
        while(st.empty()){
            vector<string> arr = {"1", "22", "122", "333", "1333", "4444", "14444", "22333", "55555","122333", "155555", "224444", "666666"};
            for(string s: arr){
                while(!st.count(stoi(s))){
                    st.insert(stoi(s));
                    nextPermutation(s);
                }
            }
            st.insert(1224444);

        }
        return *upper_bound(st.begin() , st.end() , n);

        
    }
};