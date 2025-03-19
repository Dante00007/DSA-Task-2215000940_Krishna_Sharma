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
        int n = intervals.size();
        j = n-(j+1);
        for(int i=1;i<=j;i++)
            intervals.pop_back();

        return intervals;
    }
};