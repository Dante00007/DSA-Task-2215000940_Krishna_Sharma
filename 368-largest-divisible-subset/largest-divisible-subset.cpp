class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       vector<int> dp(n,1),parent(n);

        int maxi = 1;
        int lastIndex = 0;

        for(int i =0;i<n;i++){
            parent[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    if(dp[i]<1+dp[prev]){
                        dp[i]= 1+dp[prev];
                        parent[i]  = prev;
                    }
                    cout<<dp[i]<<" ";
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex = i;      
            }
        }
    // cout<<lastIndex;
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while(parent[lastIndex]!=lastIndex){
        lastIndex = parent[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};