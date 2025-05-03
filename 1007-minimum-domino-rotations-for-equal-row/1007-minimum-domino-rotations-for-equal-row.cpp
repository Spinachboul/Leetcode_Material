class Solution {
private:
    int check(int x, vector<int>& a, vector<int> &b){
        int counta = 0, countb = 0;
        int n = a.size();
        for(int i=0 ; i<n ; i++){
            if(x != a[i] && x != b[i]) return -1;
            else if(x != a[i]) counta++;
            else if(x != b[i]) countb++;
        }
        return min(counta, countb);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = check(tops[0] , tops, bottoms);
        if(ans != -1 || tops[0] == bottoms[0]) return ans;
        return check(bottoms[0] , tops, bottoms);
    }
};