class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int step = 0;
        while(target>startValue){
            // checking if even
            if(!(target&1)){
                target /= 2;
            }else{
                target+=1;
            }
            step++;
        }
        return step + (startValue - target);;
    }
};