class Solution {
public:
    // set<int> visited;
    // void dfs(int src,vector<vector<int>> adjList){
    //     stack<int> st;
    //     st.push(src);
    //     while(!st.empty()){
    //         int vtx = st.top();
    //         st.pop();
    //         if(visited.contains(vtx)) continue;
    //         visited.insert(vtx);
    //         for(auto nbr: adjList[vtx]){
    //             if(!visited.contains(nbr))
    //                 st.push(nbr);
    //         }
    //     }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     vector<vector<int>> adjList(n);

    //     // Create Adjacency List
    //     for(int i = 0;i<n;i++){
    //         for(int j = 0;j<n;j++){
    //             if(isConnected[i][j]==1){
    //                 adjList[i].push_back(j);
    //                 adjList[j].push_back(i);
    //             }
    //         }
    //     }
        
    //     int count = 0;
    //     for(int i = 0;i<n;i++){
    //         if(!visited.contains(i)){
    //             dfs(i,adjList);
    //             count++;
    //         } 
    //     }
    //     return count;
    // }


    // method 2 using DSU
    class DisjointSet{
    
    // DisjointSet
    public:
        vector<int> rank,parent,size;
        DisjointSet(){}
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 1;i<=n;i++){
                parent[i] = i;
            }

            size.resize(n+1,1);

        }

        int findUparent(int node){
            if(parent[node]==node) return node;
            // path compression
            return parent[node] = findUparent(parent[node]);
        }

    //  Union can be done by two method
        void unionByRank(int u,int v){
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u==ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;  
            }
            else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u,int v){
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];  
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_v]+=size[ulp_u]; 
            }
        }
};
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }

        return cnt;
    }
};