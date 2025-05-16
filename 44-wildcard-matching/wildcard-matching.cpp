class Solution {
public:
    bool isAllStars(string &S1, int i) {
    
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }
    bool solve(string s,string p,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1==s.size() && idx2==p.size()) return true;

        if(idx1<s.size() && idx2==p.size()) return false;

        if(idx1==s.size() && idx2<p.size()) return isAllStars(p,idx2);

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        bool ans;
        if(s[idx1]==p[idx2] || p[idx2]=='?') 
            return dp[idx1][idx2] = solve(s,p,idx1+1,idx2+1,dp);
        else{
            if(p[idx2]=='*'){
                return dp[idx1][idx2]= solve(s,p,idx1+1,idx2,dp) 
                            || solve(s,p,idx1,idx2+1,dp);
            }
            else {
                return dp[idx1][idx2] =  false;
            }   
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return solve(s,p,0,0,dp);

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i = 1;i<=m;i++){
            dp[0][i] = isAllStars(p,i);
        }
    
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else{
                    if(p[j-1]=='*')
                        dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
                    else
                        dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
};