class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0;
        int e = nums.size()-1;
        int mid = (s+e)/2;
        // if(nums[s]<nums[e]) return nums[s];
        while(s<=e){
            if(nums[mid]<=nums[e]){ 
                ans = min(ans,nums[mid]);
                e=mid-1;
            }
            else s = mid+1;
            mid = (s+e)/2;
        }
        return ans;
    }
};