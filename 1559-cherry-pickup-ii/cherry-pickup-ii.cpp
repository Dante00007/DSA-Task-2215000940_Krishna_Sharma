class Solution {
public:
    int solve(vector<vector<int>>& grid,int row,int col1,int col2,
        vector<vector<vector<int>>> &dp){
        if(col1<0 || col2>=grid[0].size() || col2<0 ||col1>=grid[0].size()) 
            return INT_MIN;
        if(row==grid.size()-1){
            if(col1==col2){
                return grid[row][col1];
            }
            else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int maxi = INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int value = 0;
                if(col1==col2){
                    value = grid[row][col1];
                }
                else {
                    value = grid[row][col1]+grid[row][col2];
                }
                value+=solve(grid,row+1,col1+i,col2+j,dp);
                maxi = max(maxi,value);
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};