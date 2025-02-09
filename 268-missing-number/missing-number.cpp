class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int i = 0;
        while(i<n){
            sum+=nums[i++];
        }
        int sumFormula = (n*(n+1))/2;
        return sumFormula - sum;
    }
};