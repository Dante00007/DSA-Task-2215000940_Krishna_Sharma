class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);

        for(auto it:prerequisites){
            int v = it[0];
            int u = it[1];
            indegree[v]++;
            adjList[u].push_back(v);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};