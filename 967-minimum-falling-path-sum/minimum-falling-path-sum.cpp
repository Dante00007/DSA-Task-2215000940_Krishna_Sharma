class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& dp){
        if(col>=matrix.size() || col<0) return INT_MAX;
        if(row==matrix.size()-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];

        int mini = INT_MAX;
        for(int i = col-1;i<=col+1;i++){
            mini = min(mini,solve(matrix,row+1,i,dp));
        }
        if(mini==INT_MAX) mini = 0;
        return dp[row][col] = mini + matrix[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Still TLE Solution
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // int mini = INT_MAX;
        // for(int i = 0;i<n;i++){
        //     mini = min(mini,solve(matrix,0,i,dp));
        // }
        // return mini;

        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(auto it:dp){
            for(auto ele:it){
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int lessJ = INT_MAX;
                int moreJ = INT_MAX;
                if(j>0) lessJ = dp[i-1][j-1];
                if(j<n-1) moreJ = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + 
                            min(dp[i-1][j],min(lessJ,moreJ));
            }
        }
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};