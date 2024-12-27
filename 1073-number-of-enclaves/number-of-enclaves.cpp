class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        for(auto [dr,dc]:dir){
                int nbrRow = row +dr;
                int nbrCol = col + dc;
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                 !vis[nbrRow][nbrCol] && grid[nbrRow][nbrCol]!=0){
                    dfs(grid,vis,nbrRow,nbrCol);
                 }
            }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));

        for(int j = 0 ; j<n;j++) { 
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(grid, vis, 0, j); 
            }
            if(!vis[m-1][j] && grid[m-1][j] == 1) {
                dfs(grid, vis,m-1,j); 
            }
        }
        for(int i = 0;i<m;i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(grid,vis,i,0); 
            }
            
            if(!vis[i][n-1] && grid[i][n-1] == 1) {
                dfs(grid,vis,i,n-1); 
            }
        }
        int count = 0;
         for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};