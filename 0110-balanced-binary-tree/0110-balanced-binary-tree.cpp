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
int solve(TreeNode* root,int &avl){
    if(root==NULL) return 0;
    int l=solve(root->left,avl);
    int r=solve(root->right,avl);
    // left -right ssubtree;
    avl=max(avl,abs(l-r));
    // geting subtrees difference of getting higher n0. of nodes.
    return max(l,r)+1;
}
    bool isBalanced(TreeNode* root) {
        int avl=0;
        solve(root,avl);
        if(avl==0||avl==1||avl==-1) return true;
        else return false;

    }
};