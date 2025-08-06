class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // this is a concept of practicing the custim sorting
        auto compare = [](const string& log1 , const string& log2){
            int i1 = log1.find(' ');
            int i2 = log2.find(' ');

            string id1 = log1.substr(0, i1);
            string id2 = log2.substr(0, i2);

            string content1 = log1.substr(i1+1);
        }
};