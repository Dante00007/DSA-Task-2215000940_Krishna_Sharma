class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m,vector<int> (n,1e9));
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>> > pq;
        
        effort[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==m-1 && col==n-1) return diff;
            for(int i =0;i<4;i++){
                int nurow = dx[i] + row;
                int nucol = dy[i] + col;
                if(nurow >= 0 && nurow < m && nucol >= 0 && nucol < n){    
                    int newEffort = max(diff,abs(heights[row][col]-heights[nurow][nucol]));
                    if(newEffort<effort[nurow][nucol]){    
                        effort[nurow][nucol] = newEffort;
                        pq.push({newEffort,{nurow,nucol}});
                    }
                }

            }

        }
        return 0;
    }
};