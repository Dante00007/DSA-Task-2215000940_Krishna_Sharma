class Solution {
public:
    set<int> visited;
    void dfs(int src,vector<vector<int>> adjList){
        stack<int> st;
        st.push(src);
        while(!st.empty()){
            int vtx = st.top();
            st.pop();
            if(visited.contains(vtx)) continue;
            visited.insert(vtx);
            for(auto nbr: adjList[vtx]){
                if(!visited.contains(nbr))
                    st.push(nbr);
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
        
        int count = 0;
        for(int i = 0;i<n;i++){
            if(!visited.contains(i)){
                dfs(i,adjList);
                count++;
            } 
        }
        return count;
    }
};