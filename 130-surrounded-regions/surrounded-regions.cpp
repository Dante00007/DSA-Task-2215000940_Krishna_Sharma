class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        for(auto [dr,dc]:dir){
                int nbrRow = row +dr;
                int nbrCol = col + dc;
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                 !vis[nbrRow][nbrCol] && board[nbrRow][nbrCol]!='X'){
                    dfs(board,vis,nbrRow,nbrCol);
                 }
            }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || i==m-1 || j==n-1 || j==0) && 
                    vis[i][j]==0) {
                    dfs(board,vis,i,j);
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};