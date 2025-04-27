class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int cost = q.front().first;
            int node = q.front().second.first;
            int stop = q.front().second.second;
            q.pop();
            if(stop>k) continue;
            for(auto [nbr,nbrCost]:adj[node]){
                if(nbrCost+cost<dist[nbr]){
                    dist[nbr] = nbrCost+cost;
                    q.push({dist[nbr],{nbr,stop+1}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};