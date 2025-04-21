class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int> > pq;
        sort(events.begin(),events.end());
        int n = events.size();
        
        int ans = 0, idx = 0;

        for (int d = 1; d <= 100000; d++) {
            while (idx < n && events[idx][0] == d) {
                pq.push(events[idx][1]);
                idx++;
            }
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }


            if (!pq.empty()) {
                ans++;
                pq.pop();
            }

            if (idx >= n && pq.empty()) break;
        }

        return ans;

    }
};