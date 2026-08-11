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
// Create child -> parent mapping
    // Also find the starting node
TreeNode* childtoparentmapping(TreeNode* root,int start,map<TreeNode*,TreeNode*>&mpp){
   
    if(root==NULL) return NULL;
     mpp[root]=NULL;
    TreeNode* target=NULL;
   queue<TreeNode*>q;
   q.push(root);
   while(!q.empty()){
    int n=q.size();
    while(n--){
        TreeNode* temp=q.front();
        q.pop();
        // Find starting node
        if(temp->val==start){
            target=temp;
        }

       // Create parent mapping for left child

        if(temp->left!=NULL){
            mpp[temp->left]=temp;
            q.push(temp->left);
        }
        // Create parent mapping for right child

         if(temp->right!=NULL){
            mpp[temp->right]=temp;
            q.push(temp->right);
        }

    }

   }
   return target;

}
// burning start from targetnode and check parent mapping to chind
int timetoburn(TreeNode* targetnode,map<TreeNode*,TreeNode*>&mpp){
    int time=0;
    // Keep track of burned/visited nodes
    map<TreeNode*,bool>visited;
    queue<TreeNode*>q;
    // Start burning from target
    q.push(targetnode);
    visited[targetnode]=true;
    while(!q.empty()){
        int n=q.size();
        bool flag=false;
        while(n--){
            TreeNode* temp=q.front();
            q.pop();
            //temp->left is not null && not visited;
            if(temp->left!=NULL && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
                flag=true;
            }
            //temp->right is not null && not visited;
             if(temp->right!=NULL && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
                flag=true;
            }
            if(mpp[temp]!=NULL && !visited[mpp[temp]]){
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
                flag=true;
            }
        }
        if(flag==true) time++;
    }
    return time;
    

}
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        TreeNode* targetnode=childtoparentmapping(root,start,mpp);
        int ans=timetoburn(targetnode,mpp);
        return ans;
        
    }
};