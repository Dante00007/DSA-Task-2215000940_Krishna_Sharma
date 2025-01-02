class DisjointSet{
    // DisjointSet
    public:
    vector<int> rank,parent,size;
        DisjointSet(){}
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 1;i<=n;i++){
                parent[i] = i;
            }

            size.resize(n+1,1);

        }

        int findUparent(int node){
            if(parent[node]==node) return node;
            // path compression
            return parent[node] = findUparent(parent[node]);
        }

    //  Union can be done by two method
        void unionByRank(int u,int v){
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u==ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;  
            }
            else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u,int v){
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];  
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_v]+=size[ulp_u]; 
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        DisjointSet ds(n);
        for(int i = 0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
            vector<vector<string>> mergedMail(n);
            for(auto it:mp){
                int node = ds.findUparent(it.second);
                string mail = it.first;
                mergedMail[node].push_back(mail);
            }

            vector<vector<string>> ans;
            for(int i=0;i<n;i++){
                if(mergedMail[i].size()==0) continue;
                sort(mergedMail[i].begin(),mergedMail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto it:mergedMail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        return ans;
    }
};