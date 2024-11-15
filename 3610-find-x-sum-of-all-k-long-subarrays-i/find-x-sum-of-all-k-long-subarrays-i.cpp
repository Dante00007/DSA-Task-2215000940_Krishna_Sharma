class Solution {
public:
    int calculate(unordered_map<int, int>& m,int x){
        priority_queue<pair<int,int>> pq;

        for(auto &p:m){
            pq.push({p.second,p.first});
        }
        int sum = 0;
        while(x>0 && !pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            sum+=p.first*p.second;
            x--;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> m;

        for(int i =0;i<k;i++){
            m[nums[i]]++; 
        }

        ans.push_back(calculate(m,x));
        for(int i=1;i<=n-k;i++){
            m[nums[i-1]]--;
            if(m[nums[i-1]]==0)
                m.erase(nums[i-1]);

            m[nums[i+k-1]]++;

            ans.push_back(calculate(m,x));
        }
        return ans;
    }
};