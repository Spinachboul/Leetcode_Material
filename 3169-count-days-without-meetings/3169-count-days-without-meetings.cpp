class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0;
        int lastEnd = 0;
        sort(meetings.begin() , meetings.end());
        for(auto& meeting: meetings){
            int start = meeting[0];
            int end = meeting[1];

            if(start > lastEnd + 1){
                freeDays += start - lastEnd - 1;
                
            }
            lastEnd = max(lastEnd, end);
            
        }
        freeDays += days - lastEnd;
        return freeDays;

        
        


        
    }
};