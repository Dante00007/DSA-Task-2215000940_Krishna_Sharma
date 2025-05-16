class Solution {
public:
    int solve(vector<int> &prices,int idx,int buy,int transaction, vector<vector<vector<int>>> &dp){
        if(idx==prices.size() || transaction==0) return 0;

        if(dp[idx][buy][transaction]!=-1) return dp[idx][buy][transaction];

        int profit = 0;

        if(buy){
            profit = max(solve(prices,idx+1,1,transaction,dp),
                            -prices[idx]+solve(prices,idx+1,0,transaction,dp));
        }
        else{
            profit = max(solve(prices,idx+1,0,transaction,dp),
                        prices[idx]+solve(prices,idx+1,1,transaction-1,dp));
        }

        return dp[idx][buy][transaction] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};