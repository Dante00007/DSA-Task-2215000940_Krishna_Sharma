class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x/2+1;
        long long int ans =-1;
        long long int mid = s +(e-s)/2;
        long long int sqr = mid*mid ;  
        while(s<=e){
            sqr = mid*mid;
            if(sqr<=x){
                ans = mid;
                s = mid+1;
            }
            else e = mid -1;
            mid = s + (e -s)/2;
        }
        return ans;
    }
};