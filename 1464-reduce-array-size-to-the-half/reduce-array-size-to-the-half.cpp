class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto it:arr){
            m[it]++;
        }

        priority_queue<int> pq;

        for(auto it:m){
            pq.push(it.second);
        }

        int sz = arr.size()/2;
        int i = 0;
        int removed = 0;
        while(!pq.empty()){
            removed+=pq.top();
            pq.pop();
            i++;
            if(removed>=sz) return i;
            
        }
        return i;
    }
};