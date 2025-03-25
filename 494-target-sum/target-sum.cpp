class Solution {
public:
    int solve(vector<int>& nums,int idx,int d,int tot,unordered_map<string, int>& dp){
        if(idx>=nums.size()){
            if(tot==d) return 1;
            return 0;
        }
        
        string key = to_string(idx) + "," + to_string(tot);
        
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

            
            
        int add = solve(nums,idx+1,d,tot+nums[idx],dp);
        int sub = solve(nums,idx+1,d,tot-nums[idx],dp);

        return dp[key] = sub + add;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return solve(nums, 0, target, 0, dp);
    }
};