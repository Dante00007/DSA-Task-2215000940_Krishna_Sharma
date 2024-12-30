class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        queue< pair<int,pair<int,int>> > q;
        
        vector<int> dx{-1, -1, -1,  0, 0, 1, 1, 1};
        vector<int> dy{-1,  0,  1, -1, 1, -1, 0, 1};
        
        if(grid[0][0]!=1){
            q.push({1,{0,0}});
            dist[0][0] = 1;
        }
        while(!q.empty()){
            int cost = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nurow = dx[i] + row;
                int nucol = dy[i] + col;

                if(nurow >= 0 && nurow < n && nucol >= 0 && nucol < n &&
                    (cost+1<dist[nurow][nucol]) && grid[nurow][nucol]==0){
                        dist[nurow][nucol] = cost + 1;
                        q.push({cost+1,{nurow,nucol}});
                    }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};