class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        m[0] = 1;
        int cum_sum = 0;
        int total_subarray = 0;

        for(int num:nums){
            cum_sum+=num;
            if(m.find(cum_sum - goal)!=m.end()){
                total_subarray+=m[cum_sum-goal];
            }
            m[cum_sum]++;
        }
        return total_subarray;
    }
};