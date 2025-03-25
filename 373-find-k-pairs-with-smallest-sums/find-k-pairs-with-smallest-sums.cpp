class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],0});
        }

        while(!pq.empty() && k!=0){
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans.push_back({sum-nums2[idx],nums2[idx]});
            k--;

            if(idx+1<nums2.size()){
                pq.push({sum-nums2[idx]+nums2[idx+1],idx+1});
            }
        }
        return ans;
    }
};