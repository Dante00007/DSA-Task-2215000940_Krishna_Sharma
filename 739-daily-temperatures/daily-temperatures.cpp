class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        stack<int> s;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};