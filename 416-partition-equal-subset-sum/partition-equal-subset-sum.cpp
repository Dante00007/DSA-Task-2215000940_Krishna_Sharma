class Solution {
public:
    bool solve(vector<int>& nums,int sum,int idx,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(idx>=nums.size() || sum<0) return false;

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int inc = solve(nums,sum-nums[idx],idx+1,dp);
        int exc = solve(nums,sum,idx+1,dp);

        return dp[idx][sum]= inc || exc;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        if(target&1) return false;
        target = target/2;
        // vector<vector<int> > dp(n,vector<int> (target+1 ,-1));
        // return solve(nums,target,0,dp);

        vector<vector<int> > dp(n,vector<int> (target+1 ,0));
        for(int i= 0;i<n;i++){
            dp[i][0] = 1;
        }
        if(nums[0]<=target) dp[0][nums[0]] = 1;

        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=target;t++){
                int exc = dp[ind-1][t];
                int inc = 0;
                if(nums[ind]<=t){
                    inc = dp[ind-1][t-nums[ind]];
                }
                dp[ind][t] = exc || inc;
            }
        }
        return dp[n-1][target];
    }
};