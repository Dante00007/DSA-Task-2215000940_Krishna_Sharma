class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        for(auto vec:trips){
            v[vec[1]]+= vec[0];
            v[vec[2]]-= vec[0]; 
        }

        for(auto pos:v){
            if(pos==0) continue;
            capacity-=pos;
            if(capacity<0) return false;
        }
        return true;
    }
};