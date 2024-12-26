class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,queue<pair<pair<int,int>,int>> &q){
        int m = grid.size();
        int n = grid[0].size();
        
        int minute = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            minute = max(minute,t);
            q.pop();
            vector<pair<int,int>> dir{{0,-1},{0,1},{-1,0},{1,0}};
            for(auto [dr,dc]:dir){
                int nbrRow = row + dr;
                int nbrCol = col + dc;
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                 vis[nbrRow][nbrCol]!=2 && grid[nbrRow][nbrCol]==1){
                    q.push({{nbrRow,nbrCol},t+1});
                    vis[nbrRow][nbrCol] = 2;
                 }
            }
        }
        return minute;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        time = bfs(grid,vis,q);
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};