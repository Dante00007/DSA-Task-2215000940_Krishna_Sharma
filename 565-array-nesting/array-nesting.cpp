class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<bool> seen(n);
        for(auto it:nums){
            int cnt = 0;
            while(!seen[it]){
                cnt++;
                seen[it] = true;
                it = nums[it];
            }
            res = max(res,cnt);
        }
        return res;
    }
};