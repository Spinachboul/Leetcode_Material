/**
so yea the thing that comes to my mind is that we should look for available whtiespaces then we will know which meeting are eligible for shifts. and for those events (we will mark them) now the approach will count the whiteSpace from previous end and end time as either the eventTime or the startTime of next (if the current one is marked) then we add to the whiteSpace the width of the marked event too.
oh yea so step 1 find the max size of slot... but then what if the slot is just between the space of left and right then the calculation will be wrong...
I mean the bf solution will be get the curStart get the current event get the curEnd 
and try to find that whether there is a place of that size or greater outside the current consideration. but then that would be n^2
what if I iterate from right to left and each index will store the maximum whiteSpace that exists after the current meeting? and same from the left side.
yea so I forgot the case when I can move things to add up the left and right space of the current one
 */
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