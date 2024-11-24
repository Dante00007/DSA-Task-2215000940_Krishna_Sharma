class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxi = 1;
        int l = 0;
        int r = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minPq;
        priority_queue<pair<int,int>> pq;
        while(r<nums.size()){
            
            pq.push({nums[r],r});
            minPq.push({nums[r],r});
            
            if(pq.top().first-minPq.top().first<=limit){
                maxi = max(maxi,r-l+1);
            }
            else{
        
                while(pq.top().first-minPq.top().first>limit){
                    l++;
                    while (!pq.empty() && pq.top().second < l) {
                        pq.pop();
                    }
                    while (!minPq.empty() && minPq.top().second < l) {
                        minPq.pop();
                    }
                }
            }
            r++;
        }
        return maxi;
    }
};