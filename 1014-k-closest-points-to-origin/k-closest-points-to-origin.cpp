class Compare{
    public:
    bool operator()(pair<double,pair<int,int>> &a,pair<double,pair<int,int>> &b){
        return a.first<b.first;

    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;

        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<k;i++){
            int x = points[i][0];
            int y = points[i][1];
            double diff = sqrt(pow(x,2)+pow(y,2));
            cout<<x<<" "<<y<<" "<<diff<<endl;
            pq.push({diff,{x,y}});
        }
       
        for(int i=k;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            double diff = sqrt(pow(x,2)+pow(y,2));
            cout<<x<<" "<<y<<" "<<diff<<endl;
            if(pq.top().first>diff){
                pq.pop();
                pq.push({diff,{x,y}});
            }
        }
        //  while(!pq.empty()){
        //     auto ele = pq.top().second;
        //     pq.pop();

        //     cout<<ele.first<<" "<<ele.second<<endl;
        // }
        while(!pq.empty()){
            auto ele = pq.top().second;
            pq.pop();

            ans.push_back({ele.first,ele.second});
        }

        return ans;
    }
};