class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i =0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    bool func(vector<int> piles,long long int k,int h){
        int i = 0;
        while(i<piles.size() && h>0){
            if(piles[i]%k==0){
                h-=piles[i]/k;
            }
            else{
                h-=(piles[i]/k + 1);
            }
            i++;
        }
        if(i==piles.size() && h>=0) return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = findMax(piles);
        int mid = s+(e-s)/2;
        int ans = INT_MAX;
        while(s<=e){
            if(func(piles,mid,h)){
                ans = min(ans,mid);
                e = mid -1;
            }
            else{
                s = mid +1;
            }
            mid = s+(e-s)/2;
        }

        return ans;
    }
};