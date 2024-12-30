class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue< pair<int,pair<int,int>> > q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stop>k) continue;

            for(auto it:adj[node]){
                int nuNode = it.first;
                int nuWt = it.second;
                if(cost+nuWt<dist[nuNode]){ 
                    dist[nuNode] =  cost+nuWt; 
                    q.push({stop+1,{nuNode,dist[nuNode]}});
                }
            }

        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};