class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int sz = rains.size();
        vector<int> ans(sz,-1); 
        map<int,int> rain;
        set<int> dry;
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                dry.insert(i);
            }
            else if(!rain.count(rains[i])){
                rain[rains[i]]= i;
            }
            else{
                auto it = dry.upper_bound(rain.at(rains[i]));                
                if (it == dry.end()) return {};
                ans[*it] = rains[i];
                rain[rains[i]] = i;
                dry.erase(it);
            }
        }
        for(auto s:dry){
            ans[s] = 1;
        }
       return ans;
    }
};