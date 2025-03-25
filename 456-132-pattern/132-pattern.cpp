class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        
        stack<int> s;
        int k = INT_MIN;
        vector<int> min_left(nums.size());
        min_left[0] = nums[0];
        int i = 1;
        while(i<nums.size()){
            min_left[i] = min(min_left[i-1],nums[i]);
            i++;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<k){
                return true;
            }
            while(!s.empty() && s.top()<nums[i]){
                k = s.top();
                if(k>min_left[i]) return true;
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};