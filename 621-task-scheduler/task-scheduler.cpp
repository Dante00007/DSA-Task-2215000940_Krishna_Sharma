class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> pq;
        map<char,int> m;
        queue<pair<int,int>> q;
        for(int i =0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto it:m){
            pq.push({it.second,0});
        }
    
        int time = 0;
        while(!pq.empty()|| !q.empty()){
            if(!q.empty() && (time-q.front().second>n)){
                pq.push(q.front());
                q.pop();
            }
            if(!pq.empty()){
                auto task = pq.top();
                pq.pop();
                int frq = task.first - 1;
                int cool = time;
                if(frq>0){
                    q.push({frq,cool});
                }
            }
            time++;
        }
        return time;
    }
};