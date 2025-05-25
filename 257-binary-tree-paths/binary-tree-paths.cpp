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
    // 0ms
    void solve1(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        string val = to_string(root->val);
        s+=val;
        solve1(root->left,s+"->",ans);
        solve1(root->right,s+"->",ans);
    }
    // 1ms
    void solve2(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;
        // For backtracking
        int len = s.length();
        string val = to_string(root->val);
        s+=val;
        if(root->left || root->right){
            solve2(root->left,s+"->",ans);
            solve2(root->right,s+"->",ans);
        } 
        else{
            ans.push_back(s);
        }
        s.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve2(root,"",ans);
        return ans;
    }
};