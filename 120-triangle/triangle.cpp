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
        vector<vector<int>> dp(m,vector<int> (triangle[m-1].size(),-1));
        return solve(triangle,0,0,dp);
    }
};