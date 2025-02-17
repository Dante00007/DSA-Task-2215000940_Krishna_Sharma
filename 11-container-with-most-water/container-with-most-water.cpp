class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        int i = 0;
        int maxArea = INT_MIN;
        while(i<j){
            int area = min(nums[i],nums[j]) * (j-i);
            maxArea = max(area,maxArea);
            if(nums[i]<nums[j]) i++;
            else j--;
        }
        return maxArea;
    }
};