class Solution {
public:
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size(),0);
        dp[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            int inc = arr[i];
            if(i>1){
                inc += dp[i-2];
            }
            int exc = dp[i-1];
            dp[i] = max(inc,exc);
        }
        return dp[arr.size()-1];
    }
};