class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
    array<uint8_t,26> fq{}; fq[0]=fq[4]=fq[8]=fq[14]=fq[20]=101;
    uint8_t vowel=0, cons=0;
    for (char c : s) {
        uint8_t &x = fq[c-97]; x++;
        if (x < 101) cons = max(cons, x);
        else vowel = max(vowel, uint8_t(x - 101));
    }
    return vowel + cons;
}
};