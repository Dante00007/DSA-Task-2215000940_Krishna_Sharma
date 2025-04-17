class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // we can use unordered map;
        vector<int> prefixSum(n+1,0);
        prefixSum[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (nums[i] & 1); 
            if(sum-k>=0){
                count+=prefixSum[sum -k];
            }
            prefixSum[sum]++;
               
        }
       

        return count;    
    }
};