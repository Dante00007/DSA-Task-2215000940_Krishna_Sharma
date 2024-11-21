class Compare {
public:
    bool operator()(pair<char,int> below, pair<char,int> above)
    {
        return below.second < above.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;

        for(int i =0;i<s.length();i++){
            m[s[i]]++;
        }

        for(auto it:m){
            pair<char,int> p = make_pair(it.first,it.second);
            pq.push(p);
        }
        string ans = "";
        while(!pq.empty()){
            char ch = pq.top().first;
            while(m[ch]>0){
                ans+=pq.top().first;
                m[ch]--;;
            }
            pq.pop();
        }
        return ans;
    }
};