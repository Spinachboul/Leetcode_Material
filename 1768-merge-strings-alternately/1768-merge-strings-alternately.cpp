class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string res = "";
        int i=0, j=0;
        while(i<n && j<m){
            res += word1[i];
            res += word2[j];
            i++;j++;
        }
        if(n>m){
            for(int k=i ; k<n ; k++){
                res += word1[k];
            }

        }
        else if(n<m){
            for(int k=j ; k<m ; k++){
                res += word2[k];
            }
        }
        return res;

    }
        
};