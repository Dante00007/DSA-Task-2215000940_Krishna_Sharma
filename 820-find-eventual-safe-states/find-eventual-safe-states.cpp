class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        // we need this because every outdegree equal to 0 is safe node
        // but in topo sort we have everything in indegree so we just reverse the list
        vector<vector<int>> adjRev(n);
        for(int i = 0;i<n;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjRev[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};