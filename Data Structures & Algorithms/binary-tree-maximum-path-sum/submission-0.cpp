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

    // catch is to update the maxSum and also return only left or right subtree with curr node to the parent
    int solve(TreeNode* root,int& maxSum){
        if(root==NULL){
            return 0;
        }

        int left=max(solve(root->left,maxSum),0);
        int right=max(solve(root->right,maxSum),0);

        int currSum=root->val+left+right;
        maxSum=max(maxSum,currSum);

        //return only one left/right whichever is max with curr node to parent
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int ans=solve(root,maxSum);
        return maxSum;


    }
};
