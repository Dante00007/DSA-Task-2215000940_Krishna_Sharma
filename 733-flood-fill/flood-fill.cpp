class Solution {
public:
    void dfs(int row, int col, int color,vector<vector<int>>& image,vector<vector<int>> &vis){
        int m = image.size();
        int n = image[0].size();
        vis[row][col] = 1;
        vector<pair<int,int>> dir{{0,-1},{0,1},{-1,0},{1,0}};
        for(auto [dr,dc]:dir){
            int nbrRow = row + dr;
            int nbrCol = col + dc;
            if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                 !vis[nbrRow][nbrCol] && image[nbrRow][nbrCol]==image[row][col]){
                    dfs(nbrRow,nbrCol,color,image,vis);
            }
        }
        image[row][col] = color;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        dfs(sr,sc,color,image,vis);
        return image;
    }
};