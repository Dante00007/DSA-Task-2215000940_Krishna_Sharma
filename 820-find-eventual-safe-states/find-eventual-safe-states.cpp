class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathVis,int node,vector<int> & check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                if(dfs(graph,vis,pathVis,nbr,check)) return true;
            }
            else if(pathVis[nbr]){
                return true;
            }
        }
        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i = 0;i<n;i++){
            dfs(graph,vis,pathVis,i,check);
        }

        for(int i = 0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};