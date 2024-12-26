class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col  = q.front().second;
            q.pop();

            vector<int> rowChoice{-1,0,1,0};
            vector<int> colChoice{0,-1,0,1};
            for(int i=0;i<4;i++){
                int nbrRow = row + rowChoice[i];
                int nbrCol = col + colChoice[i];
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<n && nbrCol<m &&
                     !visited[nbrRow][nbrCol] && grid[nbrRow][nbrCol]=='1'){
                        visited[nbrRow][nbrCol] = 1;
                        q.push({nbrRow,nbrCol});
                }  
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};