class Solution {
public:

    int solve(TreeNode* root, int &ans) {

        if(root == NULL) return 0;

        // l stores the value returned from left subtree
        // if negative sum of left subtree ->return 0;
        int leftsum = max(0,solve(root->left, ans));

          // if negative sum of right subtree ->return 0;
        // r stores the value returned from right subtree
        int rightsum = max(0,solve(root->right, ans));

        // Complete path through current node
        
        ans = max(ans, root->val + leftsum + rightsum);

        // Return value to parent
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        solve(root, ans);

        return ans;
    }
};