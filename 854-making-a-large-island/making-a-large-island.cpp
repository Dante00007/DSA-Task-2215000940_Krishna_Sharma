class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int adjr,int adjc,int n,int m ){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);

        vector<int> dx{-1,0,1,0};
        vector<int> dy{0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;

                for(int ind = 0;ind<4;ind++){
                    int adjr = i + dx[ind];
                    int adjc = j + dy[ind];
                    if(isValid(adjr,adjc,n,m) && grid[adjr][adjc]==1){
                        int nodeNo = i*m + j;
                        int adjNo = adjr*m + adjc;
                        ds.unionBySize(nodeNo,adjNo);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(grid[i][j]==1){
                    continue;
                } 
                set<int> visParent;
                int area = 1; 
                for(int ind=0;ind<4;ind++){
                    int adjr = i + dx[ind];
                    int adjc = j + dy[ind];
                    if(isValid(adjr,adjc,n,m)){
                        if(grid[adjr][adjc]==1){
                            int adjNo = adjr*m + adjc;
                            int parent = ds.findUPar(adjNo);
                            if(!visParent.count(parent)){
                                area += ds.size[parent];
                                visParent.insert(parent);
                            }
                        }
                    }  
                }
                ans = max(ans,area);
            }
        }
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }
        return ans;
    }
};