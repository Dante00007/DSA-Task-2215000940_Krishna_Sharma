class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size()-2;
        int index = -1;

        for(int i=left;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        for(int i = nums.size()-1;i>=0 && index!=-1;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        sort(nums.begin()+index+1,nums.end());
    }
};