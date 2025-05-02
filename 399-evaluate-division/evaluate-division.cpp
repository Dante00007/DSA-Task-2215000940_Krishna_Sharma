class Solution {
public:
    unordered_map<string,unordered_map<string,double>> graph;
    double bfs(string src,string dest){
        if(graph.find(src)==graph.end() || graph.find(dest)==graph.end())
            return -1.000000;
        unordered_set<string> s;
        queue<pair<string,double>> q;
        s.insert(src);
        q.push({src,1.00000});

        while(!q.empty()){
            string str = q.front().first;
            double cost = q.front().second;
            q.pop();
            if(str==dest){
                cout<<str<<"yes"<<endl;
                return cost;
            }
            for(auto it:graph[str]){
                if(s.find(it.first)==s.end()){
                    s.insert(it.first);
                    q.push({it.first,cost*it.second});
                }
            }
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;

        int i = 0;
        for(auto var:equations){
            graph[var[0]][var[1]] = values[i];
            graph[var[1]][var[0]] = 1/values[i];
            i++;
        }

        for(auto qu:queries){
            ans.push_back(bfs(qu[0],qu[1]));
        }


        
        return ans;
    }
};