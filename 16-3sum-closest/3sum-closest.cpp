class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int closest = -1;
        int prevDist = INT_MAX;
        while(i<n-2){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[k] + nums[j];
                
                if(abs(target-sum)<prevDist){
                    closest = sum;
                    prevDist = abs(target - sum);
                }

                if(sum<=target) j++;
                else k--;
            }
            i++;
        }
        return closest;
    }
};