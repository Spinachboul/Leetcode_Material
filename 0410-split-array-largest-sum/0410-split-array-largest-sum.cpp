class Solution {
public:
    bool isValid(vector<int>& nums, int n,int m , int maxPages){
        if(m>n)return false;
        int student =1,pages=0;
        for(int i=0; i<n; i++){

            if(nums[i]>maxPages){
                return false;
            }

            if(pages+nums[i]<= maxPages){
                pages+=nums[i];

            }else{
                student++;
                pages=nums[i];
            }
        }
        return student>m ? false: true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int end=0;
        for(int i=0; i<n; i++){
            end+=nums[i];
        }
        int st=0;
        int ans=-1;
        while (st<=end){
            int mid= st +(end-st)/2;

            if(isValid(nums,n,k,mid)){//left 
                ans=mid;
                end=mid-1;
            }else{//right
                st=mid+1;
            }
        }
        return ans;
    }
};