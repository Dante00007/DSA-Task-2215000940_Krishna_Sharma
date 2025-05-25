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
    void solve(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;

        string val = to_string(root->val);
        s+=val;
        if(root->left || root->right){
            solve(root->left,s+"->",ans);
            solve(root->right,s+"->",ans);
        } 
        else{
            ans.push_back(s);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,"",ans);
        return ans;
    }
};