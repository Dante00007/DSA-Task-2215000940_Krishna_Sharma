class Solution {
public:
    bool solve(vector<int>& nums,int target,int idx,int sum,vector<vector<int>> &dp){
        if(target/2==sum) return true;
        if(idx>=nums.size() || sum>target/2) return false;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int inc = solve(nums,target,idx+1,sum+nums[idx],dp);
        int exc = solve(nums,target,idx+1,sum,dp);

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
        return solve(nums,target,0,0,dp);
    }
};