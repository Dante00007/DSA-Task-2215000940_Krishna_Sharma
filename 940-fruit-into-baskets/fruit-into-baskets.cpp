class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int maxLength = 0;

        while(r<n){
            m[fruits[r]]++;
            if(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0) m.erase(fruits[l]);
                l++;
            }else{
                maxLength = max(maxLength,r-l+1);
            }
            r++;
        }

        
        return maxLength;
    }
};