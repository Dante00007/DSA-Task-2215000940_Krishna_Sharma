class Solution {
public:
    int solve(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>& dp){
        if(row==triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col]!=-1) return dp[row][col];

        return dp[row][col] = triangle[row][col] + 
                                min(solve(triangle,row+1,col,dp),
                                    solve(triangle,row+1,col+1,dp)); 
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // vector<vector<int>> dp(m);
        // for(int i=0;i<m;i++){
        //     dp[i] = vector<int> (triangle[i].size(),-1);
        // }
        // return solve(triangle,0,0,dp);

        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++){
            dp[i] = vector<int> (triangle[i].size(),0);
        }
        dp[0][0] = triangle[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
        }

        for(int i=1;i<m;i++){
            for(int j =1;j<triangle[i].size();j++){
                int sum = triangle[i][j];
                if(j==i){
                    dp[i][j] = sum+dp[i-1][j-1];
                }else{
                    dp[i][j] = sum + min(dp[i-1][j-1],dp[i-1][j]);
                }
            }
        }
        int maxi = INT_MAX;
        for(int i = 0;i<triangle[m-1].size();i++){
            maxi = min(maxi,dp[m-1][i]);
        }
        return maxi;
    }
};