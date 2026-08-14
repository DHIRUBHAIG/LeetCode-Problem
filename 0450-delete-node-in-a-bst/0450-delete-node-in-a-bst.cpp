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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            //0 child;
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //1 child;
            //left child;
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            // right child;
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            // 2 child;
            else{
                TreeNode* temp=root->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                //copy temp val in root val;
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
                
                

            }

        }
        else if(root->val>key){
            //Go root->left as a root->left as a root;
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};