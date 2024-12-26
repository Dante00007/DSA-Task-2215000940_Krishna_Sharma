class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            row = q.front().first;
            col  = q.front().second;
            q.pop();

            if(visited[row][col]==1) continue;
            visited[row][col] = 1;
            vector<int> rowChoice{-1,0,1,0};
            vector<int> colChoice{0,-1,0,1};
            for(int i=0;i<4;i++){
                int nbrRow = row + rowChoice[i];
                int nbrCol = col + colChoice[i];
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                     !visited[nbrRow][nbrCol] && grid[nbrRow][nbrCol]=='1'){
                        q.push({nbrRow,nbrCol});
                }  
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};