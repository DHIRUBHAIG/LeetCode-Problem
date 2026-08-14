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
bool isvalid(TreeNode* root,long long low,long long high){
    if(root==NULL) return true;
    if(low>=root->val || high<=root->val){
        return false;
    }
    if(!isvalid(root->left,low,root->val)){
        return false;
    }
    if(!isvalid(root->right,root->val,high)){
        return false;
    }
    return true;
    

}
//Each node must stay within a valid range:
    bool isValidBST(TreeNode* root) {
       return isvalid(root,LLONG_MIN,LLONG_MAX);
    }
};