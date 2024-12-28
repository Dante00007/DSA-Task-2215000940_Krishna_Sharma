class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]]++;
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return cnt==numCourses;
    }
};