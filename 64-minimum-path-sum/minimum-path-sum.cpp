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
        vector<vector<int>> dp(m,vector<int> (n,-1));

        return solve(grid,m-1,n-1,dp); 
    }
};