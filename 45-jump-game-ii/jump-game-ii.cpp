class Solution {
public:
    int solve(vector<int>& arr,int index,vector<int> &dp){
        if(index >= arr.size()-1)
            return 0;  
        if(arr[index]==0) 
            return INT_MAX; 
        if(dp[index]!=-1) return dp[index];
        int mini = INT_MAX;
        for(int i = 1; i <= arr[index]; i++) {
            int steps = solve(arr,index+i,dp);
            if(steps!=INT_MAX)
                mini = min(1+steps, mini);
        }
        dp[index] = mini;
        return mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};