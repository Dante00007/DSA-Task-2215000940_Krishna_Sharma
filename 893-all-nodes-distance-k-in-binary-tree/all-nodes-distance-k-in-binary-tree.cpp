/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> m; //{parent , distance from target}
    vector<int> ans;
    void dfs(TreeNode* root,int k,int len){
        if(root==NULL ) return ;
        if(m.count(root)) len = m[root];
        if(len==k) ans.push_back(root->val);

        dfs(root->left,k,len+1);
        dfs(root->right,k,len+1);
    }
    int solve(TreeNode* root, TreeNode* target, int k){
        if(root==NULL) return -1;

        if(root==target){
            m[root] = 0;
            return 0;
        }

        int l = solve(root->left,target,k);
        if(l>=0){
            m[root] = l+1;
            return l+1;
        }

        int r = solve(root->right,target,k);
        if(r>=0){
            m[root] = r +1;
            return r+1;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        solve(root,target,k);
        dfs(root,k,0);
        return ans;
    }
};