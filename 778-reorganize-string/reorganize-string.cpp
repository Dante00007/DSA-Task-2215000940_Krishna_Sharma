class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        priority_queue<pair<int,char>> pq;

        for(auto chr:s){
            m[chr]++;
        }  
        for(auto entry:m){
            pq.push({entry.second,entry.first});
        }
        
        string ans = "";
        while(pq.size()>1){
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();

            ans+=char1;
            ans+=char2;

            freq1-=1;
            freq2-=1;
            if(freq1>0) pq.push({freq1,char1});
            if(freq2>0) pq.push({freq2,char2});

        }
        if(!pq.empty()){
            auto [freq, ch] = pq.top();
            if (freq > 1) return "";
            ans += ch;
        }
        return ans;
    }
};