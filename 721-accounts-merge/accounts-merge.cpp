class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(){}
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }
    int findUparent(int node){
        if(parent[node]==node) return node;
            
        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string,int> m;
        DisjointSet ds(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(m.find(mail)==m.end()){
                    m[mail] = i;
                }
                else{
                    ds.unionBySize(i,m[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it:m){
            int node = ds.findUparent(it.second);
            string mail = it.first;
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto num:mergedMail[i]){
                temp.push_back(num);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};