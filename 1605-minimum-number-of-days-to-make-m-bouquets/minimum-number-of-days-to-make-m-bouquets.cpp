class Solution {
public:
int findMax(vector<int>& bloomDay){
        int maxi = INT_MIN;
        int n = bloomDay.size();
        for(int i =0;i<n;i++){
            maxi = max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    bool func(int mid,vector<int>& bloomDay,int m,int k){
        int i = 0;
        int flower = 0;
        while(i<bloomDay.size() && m>0){
            if(bloomDay[i]<=mid){
                flower++;
                if(flower==k){
                    m--;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
            i++;
        }
        if(m==0) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        if(n/k<m) return -1;
        int s = *min_element(bloomDay.begin(),bloomDay.end());
        int e = findMax(bloomDay);
        int mid = s+(e-s)/2;
        while(s<=e){
           
            if(func(mid,bloomDay,m,k)){
                e = mid -1;
               
            }
            else{
                s = mid + 1;
            }
            mid =  s+(e-s)/2;
        }
        return s;
    }
};