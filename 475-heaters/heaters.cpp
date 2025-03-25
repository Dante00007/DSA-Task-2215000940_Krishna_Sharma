class Solution {
public:
    bool possible(vector<int>& houses, vector<int>& heaters,int radii){
        int i = 0;
        int j = 0;
        while(i<houses.size() && j<heaters.size()){
            if(abs(heaters[j]-houses[i])<=radii){
                i++;
            }
            else{
                j++;
            }
        }
        if(j==heaters.size()) return false;
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        int s = 0;
        int e = max(houses[n-1],heaters[heaters.size()-1]);

        int radius = 0;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(possible(houses,heaters,mid)){
                radius = mid;
                e = mid -1; 
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return radius;
    }
};