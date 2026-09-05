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
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        unsigned long long ans = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int n = q.size();

            unsigned long long first = q.front().second;
            unsigned long long left = 0;
            unsigned long long right = 0;

            for (int i = 0; i < n; i++) {

                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;

                unsigned long long ind = temp.second - first;

                if (i == 0)
                    left = ind;

                if (i == n - 1)
                    right = ind;

                if (node->left)
                    q.push({node->left, 2 * ind + 1});

                if (node->right)
                    q.push({node->right, 2 * ind + 2});
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};