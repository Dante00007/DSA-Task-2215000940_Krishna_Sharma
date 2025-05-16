class Solution {
public:
    int solve(vector<int>& prices,int idx,int buy,vector<vector<int>> &dp){
        if(idx==prices.size()){
            return 0;
        }

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        int profit = 0;

        if(buy){
            profit = max(solve(prices,idx+1,1,dp),-prices[idx]+solve(prices,idx+1,0,dp));
        }else{
            profit = max(solve(prices,idx+1,0,dp),prices[idx]+solve(prices,idx+1,1,dp));
        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n ,vector<int> (2,-1));
        return solve(prices,0,1,dp);
    }
};