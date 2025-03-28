class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i = 0;i<flowerbed.size();i++){
            if(n==0) return true;
            if(flowerbed[i]!=1){
                if((i>0 && flowerbed[i-1]==1)||(i<flowerbed.size()-1 && flowerbed[i+1]==1)){
                    continue;
                }
                flowerbed[i] = 1;
                n--;
            }
        }
        return n==0;
    }
};