class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int missing = -1;
        int duplicate = -1;
        int i = 1;
        while(i<=nums.size()){
            if(m[i]>1) duplicate = i;
            if(m[i]==0){
                missing = i;
            }
            i++;
        }
        return {duplicate,missing};
    }
};