class Solution {
public:
    int dfs(vector<vector<int>> &adjList,int node,vector<int> &vis){
        vis[node] = 1;
        int maxi = 0;
        for(auto nbr:adjList[node]){
            if(!vis[nbr]){
                maxi = max(maxi,1+dfs(adjList,nbr,vis));
            }
        }

        vis[node] = 0;
        return maxi;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> adjList(n);

        // for(auto vec:edges){
        //     adjList[vec[0]].push_back(vec[1]);
        //     adjList[vec[1]].push_back(vec[0]);
        // }

        // int minHeight = INT_MAX;
        // vector<int> maxHeight(n,0);
        // vector<int> vis(n,0);
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     maxHeight[i] = dfs(adjList,i,vis);
        //     minHeight = min(minHeight,maxHeight[i]);
        // }
        // for(int i= 0;i<n;i++){
        //     if(maxHeight[i]==minHeight){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        if(n==1) return {0};
        vector<vector<int>> adjList(n);
        vector<int> indegree(n,0);
        for(auto vec:edges){
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
            indegree[vec[1]]++;
        }

        queue<int> leaves;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                leaves.push(i);
            }
        }

        int remainingNodes = n;
        while(remainingNodes>2){
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;

            for(int i=0;i<leavesCount;i++){
                int leaf= leaves.front();
                leaves.pop();
                for(int nbr:adjList[leaf]){
                    indegree[nbr]--;
                    if(indegree[nbr]==1){
                        leaves.push(nbr);
                    }
                }
            }
        }

        vector<int> ans;
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};