class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(s.contains(nums[i])){
                s.erase(nums[i]);
            }
            else{
                return true;
            }
        }

        return false;
    }
};