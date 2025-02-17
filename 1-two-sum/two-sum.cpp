class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;

        int i=0;

        while(i<nums.size()){
            int ele = nums[i];
            if(m.find(target-ele)!=m.end()){
                return {i,m[target-ele]};
            }else{
                m[ele] = i;
            }
            i++;
        }
        return {-1,-1};
    }
};