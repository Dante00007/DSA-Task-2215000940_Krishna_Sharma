class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k>0){
            int mini = pq.top().first*multiplier;
            int idx = pq.top().second;
            pq.pop();
            nums[idx] = mini;
            pq.push({mini,idx});
            k--;
        }

        return nums;
    }
};