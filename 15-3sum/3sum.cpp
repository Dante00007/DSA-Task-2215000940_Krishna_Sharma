class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int i = 0;
        while(i<n-2){
            if (i > 0 && nums[i] == nums[i - 1]){
                i++;
                continue;
            }
            int j = i+1;
            int k = n-1;
            int sum = nums[i];
            while(j<k){
                if(sum+nums[j]+nums[k]>0){
                    k--;
                }
                else if(sum+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while (nums[j] == nums[j - 1] && j < k)
                        ++j;
                }
            }
            i++;
        }
        
        return ans;
    }
};