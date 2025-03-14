class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long i = candies.size();

        // maine socha divide krna hoga, factors lagane honge,
        // kuch kuch approach lagani hogi, tabhi kuch na kuch hoga


        // editor ne seedhe bola, kuch nahi krna, bas observe krna hai, kisko kitna mil sakta hai
        // jo bhi last mein pucha gaya hai, wahi se tum question krna start kro

        int right = *max_element(candies.begin() , candies.end());
        int left = 0;

        while(left < right){
            // if can distribute, can allocate, can assign
            int mid = (left + right + 1)/2;

            if(canAllocate(candies, k, mid)){
                left = mid;
            }
            else right = mid-1;
        }
        return left;   
    }

private:
    bool canAllocate(vector<int> &candies, long long k, int x){
        long long int maxChildren = 0;

        for(int i=0 ; i < candies.size() ; i++){
            maxChildren += candies[i] / x;
        }
        return maxChildren >= k;
}
};