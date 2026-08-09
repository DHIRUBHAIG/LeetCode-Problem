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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         queue<TreeNode*>q;
        if(root==NULL)return ans;
        bool lefttoright=true;
        q.push(root);
        while(!q.empty()){
            vector<int>arr;
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                arr.push_back(temp->val);
                    if(temp->left!=NULL){
                    q.push(temp->left);
                     }
                   if(temp->right!=NULL){
                    q.push(temp->right);
                    }
                
            }
            if(!lefttoright){
                reverse(arr.begin(),arr.end());
            }
            ans.push_back(arr);
            lefttoright=!lefttoright;
            
        }
        
    
        return ans;
    }
};