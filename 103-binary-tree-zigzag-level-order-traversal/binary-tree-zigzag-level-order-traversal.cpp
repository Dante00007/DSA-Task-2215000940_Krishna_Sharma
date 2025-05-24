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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int sz = q.size();
            vector<int> op(sz);
            for(int i =0;i<sz;i++){
                root = q.front();
                
                int index  = i;
                if(!leftToRight){
                    index = sz - i -1;
                }
                op[index] = root->val;
                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                
                q.pop();
            }
            ans.push_back(op);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};