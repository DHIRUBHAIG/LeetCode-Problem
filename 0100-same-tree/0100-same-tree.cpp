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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both have Null
       if(p==NULL && q==NULL) return true;
       // either have NULL
       if(p==NULL || q==NULL) return false;
       //true  → both trees/subtrees are same
       //false → they are different
       if(p->val!=q->val) return false;
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }
};