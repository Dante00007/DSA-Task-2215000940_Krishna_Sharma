class Solution {
public:
    int solve(int idx,vector<int> &cost,vector<int> &dp){
        if(idx>=cost.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];

        int oneStep = solve(idx+1,cost,dp);
        int twoStep = solve(idx+2,cost,dp);
        
        return dp[idx]=min(oneStep,twoStep)+cost[idx]; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);

        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};