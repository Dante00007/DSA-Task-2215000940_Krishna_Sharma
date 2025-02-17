class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int i = 0;
        while(i<n-2){
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
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
            }
            i++;
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};