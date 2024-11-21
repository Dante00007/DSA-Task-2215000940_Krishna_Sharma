class Compare{
    public:
    bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
        return a.first > b.first;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>> > >pq;
        
        int n = matrix.size();

        for(int i = 0; i < n;i++){
            pq.push({matrix[i][0], {i, 0}});
        }
        int result = 0;
        

        for (int i = 0; i < k; i++){
            auto elem = pq.top();
            pq.pop();
            result = elem.first;
            int row = elem.second.first;
            int col = elem.second.second;

            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
    }

    return result;
    }
};