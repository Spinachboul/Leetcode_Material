class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int,int> cnt;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this-> nums1 = nums1;
        this-> nums2 = nums2;
        for(int num : nums2){
            ++cnt[num];

        }
        
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index]+= val;
        ++cnt[nums2[index]];
        
        
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0 ; i<nums1.size() ; i++){
            int left = tot - nums1[i];
            if (cnt.count(left)){
                ans += cnt[left];
            }

        }
        return ans;


        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */