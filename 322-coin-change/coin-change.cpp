class Solution {
public:
    int solve(vector<int>& coins, int amt,int idx, vector<vector<int>> &dp){
      
        if(idx==0){
            if(amt%coins[0]==0) return amt/coins[0];
            return 1e9;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];

        int exc =  solve(coins,amt,idx-1,dp);
        int inc = 1e9;
        if(coins[idx]<=amt) inc = 1+solve(coins,amt-coins[idx],idx,dp);

        return dp[idx][amt]=min(exc,inc);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n= coins.size();
        // vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        // int ans = solve(coins,amt,n-1,dp);
        // if(ans>=1e9) return -1;
        // return ans;
        
        vector<vector<int>>dp(n,vector<int>(amt+1,0));

        for(int T=0;T<=amt;T++){
            if(T%coins[0]==0)
                dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }
        for(int ind = 1;ind<n;ind++){
            for(int T = 1;T<=amt;T++){
                int exc =  dp[ind-1][T];
                int inc = 1e9;
                if(coins[ind]<=T) inc = 1+dp[ind][T-coins[ind]];

                dp[ind][T] = min(inc,exc);
            }
        }

        if(dp[n-1][amt]>=1e9) return -1;
        return dp[n-1][amt];
    }
};