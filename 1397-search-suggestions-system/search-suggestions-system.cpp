class TrieNode{
    // vector<TrieNode*> children(26);
    public:
    unordered_map<char,TrieNode*> children;
    vector<string> suggestions;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string& word){
        TrieNode* node = root;
        for(char c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for(string& product : products)
            insert(product);
        
        vector<vector<string>> result;
        TrieNode* node = root;

        for (char c : searchWord) {
            if (node && node->children[c])
                node = node->children[c];
            else
                node = nullptr;
            result.push_back(node ? node->suggestions : vector<string>{});
        }

        return result;
    }
};