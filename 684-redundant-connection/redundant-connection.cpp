class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }
    int findUParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u] = ulp_v;
        }else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DisjointSet ds(n);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            vector<int> temp;
            if(ds.findUParent(u)!=ds.findUParent(v)){
                ds.unionBySize(u,v);
            }
            else{
                temp.push_back(u);
                temp.push_back(v);
                ans = temp;
            }
        }
        return ans;
    }
};