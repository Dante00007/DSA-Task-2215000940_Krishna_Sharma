class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);

        for(auto it:prerequisites){
            int v = it[0];
            int u = it[1];
            indegree[v]++;
            adjList[u].push_back(v);
        }

        queue<int> q;

        for(int i = 0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return numCourses==count;
    }
};