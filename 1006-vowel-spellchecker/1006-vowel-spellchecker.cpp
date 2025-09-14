#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> words_perfect;
    unordered_map<string, string> words_cap;
    unordered_map<string, string> words_vow;

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        words_perfect.clear();
        words_cap.clear();
        words_vow.clear();

        for (auto& word : wordlist) {
            words_perfect.insert(word);

            string wordlow = toLower(word);
            if (words_cap.find(wordlow) == words_cap.end())
                words_cap[wordlow] = word;

            string wordlowDV = devowel(wordlow);
            if (words_vow.find(wordlowDV) == words_vow.end())
                words_vow[wordlowDV] = word;
        }

        vector<string> ans;
        for (auto& query : queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }

private:
    string solve(const string& query) {
        if (words_perfect.find(query) != words_perfect.end())
            return query;

        string queryL = toLower(query);
        if (words_cap.find(queryL) != words_cap.end())
            return words_cap[queryL];

        string queryLV = devowel(queryL);
        if (words_vow.find(queryLV) != words_vow.end())
            return words_vow[queryLV];

        return "";
    }

    string devowel(const string& word) {
        string ans;
        for (char c : word) {
            ans.push_back(isVowel(c) ? '*' : c);
        }
        return ans;
    }

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string toLower(const string& s) {
        string res = s;
        for (char& c : res) c = tolower(c);
        return res;
    }
};
