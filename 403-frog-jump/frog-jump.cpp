class Solution {
public:
    unordered_map<int,int> m;
    unordered_map<int, unordered_map<int, bool>> dp;
    bool solve(vector<int>& stones,int idx,int jump){
        if(idx==stones.size()-1) return true;
        if (dp[idx].count(jump)) return dp[idx][jump];

        vector<int> unit{-1,0,1};
        for(int i=0;i<3;i++){
            int currJump = unit[i] + jump;
            int currStone = stones[idx] + currJump;
            if(currJump==0 || m.find(currStone)==m.end()) continue;
            if(solve(stones,m[currStone],currJump)){
                return dp[idx][jump] = true;
            }
        }
        return dp[idx][jump] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1) return false;

        for(int i=0;i<stones.size();i++){
            m[stones[i]] = i;
        }

        return solve(stones,1,1);
    }
};