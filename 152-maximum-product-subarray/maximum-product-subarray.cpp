class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int prod = nums[i];
            for(int j = i+1;j<nums.size();j++){
                maxi = max(maxi,prod);
                prod*=nums[j];
            }
            maxi = max(maxi,prod);
        }

        return maxi; 
    }
};