class Solution {
public:
    bool solve(vector<int>& nums,int idx,vector<int>& dp){
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size() || nums[idx]==0) return false;

        if(dp[idx]!=-1) return dp[idx];

        for(int i = 1;i<=nums[idx];i++){
            if(solve(nums, i+idx, dp)) 
                return dp[idx] = true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};