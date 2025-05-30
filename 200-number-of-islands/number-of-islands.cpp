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

    int findUparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int adjr,int adjc,int m,int n ){
        return adjr>=0 && adjr<m && adjc>=0 && adjc<n;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        DisjointSet ds(m*n);
        vector<int> dx{-1,0,1,0};
        vector<int> dy{0,-1,0,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') {
                    int nodeNo = i*n + j;
                    ds.parent[nodeNo] = -1;
                    continue;
                }
                for(int ind = 0;ind<4;ind++){
                    int adjr = i + dx[ind];
                    int adjc = j + dy[ind];
                    if(isValid(adjr,adjc,m,n) && grid[adjr][adjc]=='1'){
                        int nodeNo = i*n + j;
                        int adjNo = adjr*n + adjc;
                        ds.unionBySize(nodeNo,adjNo);
                    }
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<m*n;i++){
            if(ds.parent[i]==i) cnt++;
        }
       
        return cnt;
    }
};
