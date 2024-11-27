class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto num:arr){
            int rem = ((num % k) + k) % k;
            if(m.find(rem)==m.end()){
                m[rem] = 1;
            }
            else{
                m[rem] += 1;
            }
        }

        for(auto num:arr){
            int rem = num%k;
            if(rem==0){
                if(m[rem]%2==1) return false;
            }
            else if(2*rem==k){
                if(m[rem]%2==1) return false;
            }
            else{
                if(m[rem]!=m[(k-rem)]) return false;
            }
        }
        return true;;
    }
};