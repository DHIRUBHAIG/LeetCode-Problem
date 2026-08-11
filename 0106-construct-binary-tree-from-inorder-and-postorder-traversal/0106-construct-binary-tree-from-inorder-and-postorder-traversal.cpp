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
        /*
            IMPORTANT:

            Postorder = Left → Right → Root

            We are starting from the end:

            Root → Right → Left

            Therefore, we must build RIGHT first.
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
TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int &startpostindex,int startinindex,int endinindex,int size){
    if(startpostindex<0|| startinindex>endinindex){
        return NULL;
    }
    int element=postorder[startpostindex--];
    TreeNode* root=new TreeNode(element);
    int pos=findposition(inorder,element,size);
    
    //build right subtree;
    root->right=solve(inorder,postorder,startpostindex,pos+1,endinindex,size);
    //build left subtree;
    root->left=solve(inorder,postorder,startpostindex,startinindex,pos-1,size);
     return root;


}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();
       int startpostindex=size-1;
        int startinindex=0;
        
        int endinindex=size-1;
        
        TreeNode* ans=solve(inorder,postorder,startpostindex,startinindex,endinindex,size);
        return ans; 
    }
};