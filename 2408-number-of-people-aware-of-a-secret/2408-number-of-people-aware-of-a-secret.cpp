class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> know, share;
        int k = 1, s = 0;
        know.emplace_back(1, 1);
        for(int i=2 ; i<=n ; i++){
            if(!know.empty() && know[0].first == i - delay){
                k = (k - know[0].second + mod) % mod;
                s = (s + know[0].second) % mod;
                share.push_back(know[0]);
                know.pop_front();

            }

            if(!share.empty() && share[0].first == i - forget){
                s = (s - share[0].second + mod ) % mod;
                share.pop_front();
            }

            if(!share.empty()){
                k = ( k + s) % mod;
                know.emplace_back(i,s);
            }
        }
        return (k + s) % mod;

    }

private:
    static constexpr int mod = 1000000007;
};