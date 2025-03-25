class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int index = -1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
                index = (nums[i]*-1)-1;
            }else{
                index = nums[i]-1;
            }
            if(nums[index]>0){
                nums[index] = -nums[index];
            }
            
        }
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
            i++;
        }
        return ans;
    }
};