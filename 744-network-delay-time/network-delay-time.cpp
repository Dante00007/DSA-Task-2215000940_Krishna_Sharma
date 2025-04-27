class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto vec:times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }
        vector<int> time(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int currTime = pq.top().first;
            pq.pop();
            for(auto [nbr,nbrTime]:adj[node]){
                if(nbrTime+currTime<time[nbr]){
                    time[nbr] = nbrTime + currTime;
                    pq.push({time[nbr],nbr});
                }
            }
        }
        int maxTime = 0;
        for(int t=1;t<=n;t++){
            if(time[t]==1e9) return -1;
            maxTime = max(maxTime,time[t]);
        }
        return maxTime;
    }
};