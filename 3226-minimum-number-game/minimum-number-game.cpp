class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(!pq.empty()){
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();

            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};