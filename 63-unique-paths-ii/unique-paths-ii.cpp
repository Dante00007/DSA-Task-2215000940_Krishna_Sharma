class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0 || obstacleGrid[m][n]==1) return 0;

        if(m==0 && n==0) return 1;

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = solve(obstacleGrid,m-1,n,dp)+solve(obstacleGrid,m,n-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(obstacleGrid,m-1,n-1,dp);'

        vector<vector<int>> dp(m,vector<int> (n,0));
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0] = 1;
        for(int i = 1;i<m;i++){
            if(obstacleGrid[i][0]==1) break;
            dp[i][0] = 1;
        }
        for(int i = 1;i<n;i++){
            if(obstacleGrid[0][i]==1) break;
            dp[0][i] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};