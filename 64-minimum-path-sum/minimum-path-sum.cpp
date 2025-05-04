class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){
        if(m<0 || n<0) return INT_MAX;
        if(m==0 && n==0) return grid[m][n];

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = grid[m][n] + min(solve(grid,m-1,n,dp),solve(grid,m,n-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(grid,m-1,n-1,dp); 

        vector<vector<int>> dp(m,vector<int> (n,0));

        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};