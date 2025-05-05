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
        vector<vector<int> > dp(n,vector<int> ((target/2)+1 ,-1));
        return solve(nums,target/2,0,dp);

        // vector<vector<int> > dp(n,vector<int> ((target/2)+1 ,-1));
    }
};