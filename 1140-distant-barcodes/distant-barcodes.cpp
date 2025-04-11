class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        map<int, int> m;
        vector<int> ans(n);

        for(int i = 0; i < barcodes.size(); i++){
            m[barcodes[i]]++; 
        }
        int maxNum = 0;
        int maxFreq = 0;
        for(auto it:m){
            if(it.second>maxFreq){
                maxNum = it.first;
                maxFreq = it.second;
            }
        }

        int i=0;
        while(maxFreq>0){
            ans[i] = maxNum;
            i+=2;
            maxFreq--;
        }
        m.erase(maxNum);
        if(i>=n) i = 1;

        for(auto it:m){
            int num = it.first;
            int freq = it.second;

            while(freq>0){
                ans[i] = num;
                i+=2;
                if(i>=n) i=1;
                freq--;
            }
            m.erase(num);
        }
        return ans;
    }
};