class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
    
        while(i<n){
            int validIndex = nums[i];
             while(validIndex>=1 && validIndex<=n && validIndex!=i+1 && nums[validIndex-1]!=validIndex){
                swap(nums[i],nums[validIndex-1]);
                validIndex = nums[i];
            }
            i++;
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};