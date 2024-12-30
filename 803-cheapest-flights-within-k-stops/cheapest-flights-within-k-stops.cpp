class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue< pair<int,pair<int,int>> > pq;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int cost = pq.front().first;
            int node = pq.front().second.first;
            int stop = pq.front().second.second;
            pq.pop();

            if(stop>k) continue;

            for(auto it:adj[node]){
                int nuNode = it.first;
                int nuWt = it.second;
                if(cost+nuWt<dist[nuNode]){ 
                    dist[nuNode] =  cost+nuWt; 
                    pq.push({dist[nuNode],{nuNode,stop+1}});
                }
            }

        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};