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
    pair<bool,int>solve(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        pair<bool,int>l=solve(root->left);
        pair<bool,int>r=solve(root->right);
        pair<bool,int>ans;

        if(l.first && r.first){
            if(abs(l.second-r.second)<=1){
                ans={true,max(l.second,r.second)+1};
            }
            else{
                ans={false,max(l.second,r.second)+1};
            }
        }
        else{
            ans={false,max(l.second,r.second)+1};
        }

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int>ans=solve(root);
        return ans.first;
        
    }
};
