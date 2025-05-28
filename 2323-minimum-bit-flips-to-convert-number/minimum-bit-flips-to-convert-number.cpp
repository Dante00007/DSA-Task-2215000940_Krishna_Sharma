class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int common = start & goal;

        int count = 0;
        while(goal>0 || start>0){
            int lsbGoal = goal & 1;
            int lsbStart = start & 1;
            if(lsbGoal!=lsbStart) count++;

            goal = goal>>1;
            start = start>>1;
        }
        return count;
    }
};