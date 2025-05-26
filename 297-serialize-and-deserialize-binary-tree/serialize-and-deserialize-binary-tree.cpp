/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node==NULL){ 
                    data +="#,";
                    continue;
                }
                data += to_string(node->val) +',';
                q.push(node->left);
                q.push(node->right);
                 
            }
        }
        return data;
    }
    // mine function
    vector<string> split(const string& s, char delimiter) {
       vector<string> tokens;
       stringstream ss(s);
       string token;
       while (getline(ss, token, delimiter)) {
           tokens.push_back(token);
       }
       return tokens;
   }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
       
        vector<string> vec = split(data,',');
       
        TreeNode* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);
        int n = vec.size();
        int i=1;
        while(!q.empty() || i<n){
            TreeNode* node = q.front();
            q.pop();

            if (i<n && vec[i] != "#") {
                TreeNode* leftNode = new TreeNode(stoi(vec[i]));
                node->left = leftNode;
                q.push(leftNode);
            
            }
            i++;
            if (i<n && vec[i] != "#") {
                TreeNode* rightNode = new TreeNode(stoi(vec[i]));
                node->right = rightNode;
                q.push(rightNode);
                
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));