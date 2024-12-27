class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        vector<vector<int>> vis(m,vector<int> (n,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[row][col] = dist;
            for(auto [dr,dc]:dir){
                int nbrRow = row +dr;
                int nbrCol = col + dc;
                if(nbrRow>=0 && nbrCol>=0 && nbrRow<m && nbrCol<n &&
                 !vis[nbrRow][nbrCol]){
                    vis[nbrRow][nbrCol] = 1;
                    q.push({{nbrRow,nbrCol},dist+1});
                 }
            }

        }
        return ans;
    }
};