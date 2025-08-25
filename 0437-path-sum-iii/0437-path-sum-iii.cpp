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
    int solve(TreeNode* root, long long targetSum) {
        if (root == NULL) return 0;

        int cnt = 0;
        targetSum -= root->val;

        if (targetSum == 0) cnt++;

        cnt += solve(root->left, targetSum);
        cnt += solve(root->right, targetSum);

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        return solve(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }
};
