class Solution {
public:

    set<int> vis;
    void dfs(int node,vector<vector<int>> &adjList){
        vis.insert(node);
        for(auto nbr:adjList[node]){
            if(!vis.contains(nbr)){
                dfs(nbr,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        // Create Adjacency List
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<adjList.size();i++){
            if(!vis.contains(i)){
                dfs(i,adjList);
                ans++;
            }
        }
        return ans;
    }
};