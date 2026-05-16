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

class Codec {
public:
    void serializedfs(TreeNode* root,vector<string>& res){
        if(root==NULL){
            res.push_back("N");
            return;
        }

        res.push_back(to_string(root->val));
        serializedfs(root->left,res);
        serializedfs(root->right,res);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>res;
        //preorder
        serializedfs(root,res);
        return join(res,",");
        
    }

    TreeNode* deserializedfs(vector<string>& vals,int& i){
        if(vals[i]=="N"){
            i++;
            return NULL;
        }

        TreeNode* node=new TreeNode(stoi(vals[i]));
        i++;
        node->left=deserializedfs(vals,i);
        node->right=deserializedfs(vals,i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>vals=split(data,',');
        int i=0;
        TreeNode* ans=deserializedfs(vals,i);
        return ans;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }
};
