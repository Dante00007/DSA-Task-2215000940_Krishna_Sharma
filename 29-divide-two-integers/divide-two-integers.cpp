class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
		    return INT_MAX;
  
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

   
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        for(int i=31;i>=0;i--){
            if((b<<i)<=a){
                a -= (b<<i);
                quotient |= 1LL<<i;
            }
        }
        return sign*quotient;
    }
};