class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push({gifts[i],i});
        }

        while(k>0){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            num = floor(sqrt(num));
            gifts[idx] = num;
            pq.push({num,idx});
            k--;
        }
        long long sum = 0;
        for(int i=0;i<gifts.size();i++){
            sum+=gifts[i];
        }
        return sum;
    }
};