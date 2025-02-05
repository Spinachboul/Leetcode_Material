#define vi vector<int>
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        int f = -1, s = -1;
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (f == -1) {
                    f = i;
                } else
                    s = i;
            }
        }
        if (count != 2)
            return false;

        swap(s1[f], s1[s]);
        return s1 == s2;
    }
};