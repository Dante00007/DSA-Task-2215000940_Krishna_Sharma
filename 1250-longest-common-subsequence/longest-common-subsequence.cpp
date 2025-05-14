class Solution {
public:
    int solve(string text1, string text2,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1>=text1.size() || idx2>=text2.size())
            return 0;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2])
            return dp[idx1][idx2]=1 + solve(text1,text2,idx1+1,idx2+1,dp);
        
        return dp[idx1][idx2]=max(solve(text1,text2,idx1+1,idx2,dp),
                                    solve(text1,text2,idx1,idx2+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // vector<vector<int>> dp(n1,vector<int> (n2,-1));
        // return solve(text1,text2,0,0,dp);

        vector<vector<int>> dp(n1,vector<int> (n2,0));
        for(int i=0;i<n1;i++){
            if(text1[i]==text2[0]) dp[i][0] = 1;
             else if(i > 0) dp[i][0] = dp[i-1][0];
        }
        for(int i=0;i<n2;i++){
            if(text1[0]==text2[i]) dp[0][i] = 1;
            else if(i > 0) dp[0][i] = dp[0][i-1];
        }

        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n1-1][n2-1];
    }
};