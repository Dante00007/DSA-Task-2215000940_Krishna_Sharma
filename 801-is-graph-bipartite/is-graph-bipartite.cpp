class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &color,int start){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int vtx = q.front();
            q.pop();
            for(auto nbr:graph[vtx]){
                if(color[nbr]==-1){
                    color[nbr] = !color[vtx];
                    q.push(nbr);
                }
                else if(color[vtx]==color[nbr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(graph,color,i)) return false;
            }
        }
        return true;
    }
};