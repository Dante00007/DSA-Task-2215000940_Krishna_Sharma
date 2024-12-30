class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9 + 7) ;
        vector<vector<pair<int,long long>>> adj(n);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            long long wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); 
        }
    
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
    
        priority_queue<pair<long long, int>, vector<pair<long long, int>>
            ,greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                long long edW = it.second;
                if (dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};