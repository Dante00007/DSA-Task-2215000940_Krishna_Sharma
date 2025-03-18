class Solution {
public:
    bool solve(vector<int>& nums,int idx,vector<int>& dp){
        if(idx==nums.size()-1) return 1;
        if(idx>=nums.size() || nums[idx]==0) return dp[idx]=0;

        if(dp[idx]!=-1) return dp[idx];

        for(int i = 1;i<=nums[idx];i++){
            int ans = solve(nums,idx+i,dp);
            if(ans==1) return 1;
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};