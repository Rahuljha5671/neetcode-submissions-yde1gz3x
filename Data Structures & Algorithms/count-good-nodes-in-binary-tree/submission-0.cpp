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
    void solve(TreeNode* root,int maxSeen,int& ans){
        if(root==NULL){
            return;
        }

        int m=max(root->val,maxSeen);

        if(root->val>=maxSeen){
            ans++;
        }

        solve(root->left,m,ans);
        solve(root->right,m,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int maxSeen=root->val;
        solve(root,maxSeen,ans);
        return ans;
        
    }
};
