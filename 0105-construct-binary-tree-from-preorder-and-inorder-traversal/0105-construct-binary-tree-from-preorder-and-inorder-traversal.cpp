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
int findposition(vector<int>& inorder,int element,int size){
    for(int i=0;i<size;i++){
        if(element==inorder[i]){
            return i;
        }
       
    }
    return -1;
}
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &startpreindex,int startinindex,int endinindex,int size){
    if(startpreindex>=size|| startinindex>endinindex){
        return NULL;
    }
    int element=preorder[startpreindex++];
    TreeNode* root=new TreeNode(element);
    int pos=findposition(inorder,element,size);
    //build left subtree;
    root->left=solve(preorder,inorder,startpreindex,startinindex,pos-1,size);
    //build right subtree;
    root->right=solve(preorder,inorder,startpreindex,pos+1,endinindex,size);
     return root;


}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int startpreindex=0;
        int startinindex=0;
        int size=preorder.size();
        int endinindex=size-1;
        
        TreeNode* ans=solve(preorder,inorder,startpreindex,startinindex,endinindex,size);
        return ans;
    }
};