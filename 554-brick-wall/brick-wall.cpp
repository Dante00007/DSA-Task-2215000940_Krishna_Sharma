class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<long,int> m;
        for(auto lvl:wall){
            long sum = 0;
            for(int i=0;i<lvl.size()-1;i++){
                sum+=lvl[i];
                m[sum]++;
            }
        }
        int maxi = 0;
        for(auto it:m){
            maxi = max(maxi,m[it.first]);
        }
        return wall.size() - maxi;
    }
};