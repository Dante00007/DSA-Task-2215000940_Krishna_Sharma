class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &op,int tar,int idx){
        if(tar==0){
            ans.push_back(op);
            return;
        }
        if(tar<0 || idx>=candidates.size()) return;
        solve(candidates,ans,op,tar,idx+1);
        op.push_back(candidates[idx]);
        solve(candidates,ans,op,tar-candidates[idx],idx);
        op.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(candidates,ans,op,target,0);
        return ans;
    }       
};