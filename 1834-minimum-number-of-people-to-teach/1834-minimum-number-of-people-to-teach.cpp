class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> cn;
        bool comm = false;
        
        // create the mapping between the friends and language

        for(auto& f: friendships){
            unordered_map<int, int> mp;
            bool comm = false;
            for(int lan : languages[f[0] - 1]){
                mp[lan] =1 ;
            }
            for(int lan : languages[f[1]  - 1]){
                if(mp[lan]){
                    comm = true;
                    break;
                }
            }
            if(!comm){
                cn.insert(f[0] - 1);
                cn.insert(f[1] -1 );
            }
        }

        int count = 0;
        vector<int> cnt(n+1, 0);

        for(auto& f: cn){
            for(int lan:languages[f]){
                cnt[lan]++;

                count = max(count, cnt[lan]);
            }

        }

        return cn.size() - count;



        
    }
};