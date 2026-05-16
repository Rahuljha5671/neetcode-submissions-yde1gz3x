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

    void lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans){
        if(root==NULL){
            ans=root;
            return;
        }

        if(p->val<root->val && q->val<root->val){
            lca(root->left,p,q,ans);
        }
        else if(p->val>root->val && q->val>root->val){
            lca(root->right,p,q,ans);
        }
        else if((p->val<root->val && q->val>root->val)||(p->val>root->val && q->val<root->val)){
            ans=root;
            return;
        }
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans;
        lca(root,p,q,ans);
        return ans;

        
    }
};
