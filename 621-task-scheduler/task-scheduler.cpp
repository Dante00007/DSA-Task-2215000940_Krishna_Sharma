class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int> m;
        int maxFreq = 0;
        for(auto ch:tasks){
            m[ch]++;
            maxFreq = max(maxFreq,m[ch]);
        }

        int same = 0;
        for(auto it:m){
            if(it.second==maxFreq){
                same++;
            }
        }
        int minTime = max((maxFreq - 1) * (n + 1) + same, (int)tasks.size());

        return minTime;
    }
};