class FoodRatings {

struct cmp{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
        
    }
};

unordered_map<string, pair<string,int>> mp;
unordered_map<string, set<pair<int, string>, cmp>> mp2;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            mp[foods[i]] = {cuisines[i] , ratings[i]};
            mp2[cuisines[i]].insert({ratings[i] , foods[i]});

        }
        
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine , oldRating] = mp[food];

        mp2[cuisine].erase({oldRating, food});
        mp2[cuisine].insert({newRating, food});

        oldRating = newRating;


        
    }
    
    string highestRated(string cuisine) {
        return mp2[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */