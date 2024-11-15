class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto &vec:grid){
            sort(vec.begin(),vec.end());
        }

        int sum = 0;
        int  n = grid[0].size();
        for(int i=0;i<n;i++){
            int maxi = INT_MIN;
            for(auto &vec:grid){
                int num = vec.back();
                vec.pop_back();
                if(num>maxi){
                    maxi  = num;
                }
            }
            sum+=maxi;
        }

        return sum;
    }
};