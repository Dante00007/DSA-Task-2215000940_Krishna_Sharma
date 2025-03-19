class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()<=1) return intervals;
        int i = 1;
        int j = 0;
        while(i<intervals.size()){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
            }
            else{
                j++;
                intervals[j] = intervals[i];
            }
            i++;
        }
        intervals.resize(j+1);
        return intervals;
    }
};