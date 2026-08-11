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
void solve(TreeNode* root,int targetSum,int &count,vector<int>path){
    if(root==NULL) return ;
    path.push_back(root->val);
    int s=path.size()-1;
     long long sum=0;
    for(int i=s;i>=0;i--){
         sum+=path[i];
        if(sum==targetSum) count++;
    }
    solve(root->left,targetSum,count,path);
    solve(root->right,targetSum,count,path);
    
   
    // passed by value
    // path.pop_back();

}
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int count=0;
        solve(root,targetSum,count,path);
        return count;

    }
};