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
class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUparent(u)==ds.findUparent(v)) 
                cntExtra++;
            else
                ds.unionBySize(u,v);
        }

        int numberOfComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) numberOfComponents++;
        }

        if(cntExtra>=numberOfComponents-1) return numberOfComponents-1;
        else return -1;
    }
};