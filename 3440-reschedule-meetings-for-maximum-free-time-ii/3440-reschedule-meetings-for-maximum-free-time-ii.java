class Solution {
    int left[];
    int right[];
    boolean spaceAvailable(int space,int idx){
        return left[idx]>=space||right[idx]>=space;
    }
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        this.left = new int[n];
        this.right = new int[n];
        
        int curStart = 0, curEnd = startTime[1];
        //preprocess:
        int blank = startTime[0]-0;
        for(int i=1;i<n;i++){
            left[i] = blank;
            blank = Math.max(blank,startTime[i]-endTime[i-1]);
        }
        blank = eventTime - endTime[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = blank;
            blank = Math.max(blank,startTime[i+1]-endTime[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int st = startTime[i], et = endTime[i];
            int space = et-st;
            if(spaceAvailable(space,i)){
                ans = Math.max(ans,st-curStart+ space+ curEnd-et);
            }
            else{
                ans = Math.max(ans,st-curStart+curEnd-et);
            }
            if(i+2>=n){
                curEnd= eventTime;
            }else{
                curEnd = startTime[i+2];
            }
            curStart = et;
        }
        return ans;
    }
}