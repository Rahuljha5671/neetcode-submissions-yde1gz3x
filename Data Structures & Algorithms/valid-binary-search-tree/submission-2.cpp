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
    bool isValid(TreeNode* root,int leftbound,int rightbound){
        if(root==NULL){
            return true;
        }
        if(!(root->val>leftbound && root->val<rightbound)){
            return false;
        }

        bool left=isValid(root->left,leftbound,root->val);
        bool right=isValid(root->right,root->val,rightbound);

        return (left && right);

       
    }
    bool isValidBST(TreeNode* root) {
        bool ans=isValid(root,INT_MIN,INT_MAX);
        return ans;
        
    }
};
