class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int mini = nums[0];
        int minIndex = 101;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) {
                minIndex = i;
                break;
            }
        }
        for(int i = minIndex+1;i<nums.size();i++){
            if(nums[i]>mini) return -1;
            if(nums[i-1]>nums[i]) return -1;
            // else return -1;
        }
        if(minIndex!=101 && nums[minIndex]>mini) return -1;
        if(minIndex==101) return 0;
        return nums.size()-minIndex;
    }
};