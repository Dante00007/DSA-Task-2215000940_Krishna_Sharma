class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        vector<vector<int>> adjList(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};