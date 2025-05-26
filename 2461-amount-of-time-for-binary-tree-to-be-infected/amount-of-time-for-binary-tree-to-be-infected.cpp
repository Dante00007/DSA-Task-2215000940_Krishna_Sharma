/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> m; //{ancestors,time}
    int ans = 0;

    int solve(TreeNode* root,int start){
        if(root==NULL) return -1;
        if(root->val==start){
            m[root] = 0;
            return 0; 
        }

        int l= solve(root->left,start);
        if(l>=0){
            m[root] = l+1;
            return l+1;
        }
        
        int r = solve(root->right,start);
        if(r>=0){
            m[root] = r+1;
            return r+1;
        } 
        return -1;
    }
    void dfs(TreeNode* root,int time){
        if(root==NULL) return;
        if(m.count(root)) time = m[root];

        ans = max(ans,time);
        dfs(root->left,time+1);
        dfs(root->right,time+1);
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        dfs(root,0);
        return ans;
    }
};