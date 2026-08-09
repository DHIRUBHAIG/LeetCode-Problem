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
// pass by value ,copy of value destroyed after a function
bool solve(TreeNode* root,int targetSum,int sum){
    if(root==NULL) return 0;

    sum+=root->val;
    if(root->left==NULL && root->right==NULL){
        return sum==targetSum;
    } 
    bool l=solve(root->left,targetSum,sum);
   // sum-=root->val; due to pass by  values;
    bool r=solve(root->right,targetSum,sum);
    return l||r;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
       return solve(root,targetSum,sum);
        
    }
};