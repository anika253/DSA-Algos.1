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
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return -1;
        }

        vector<int> levelSums;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            levelSums.push_back(levelSum);
        }

        int maxLevelIndex = 0;
        int maxSum = levelSums[0];

        for (int i = 1; i < levelSums.size(); i++) {
            if (levelSums[i] > maxSum) {
                maxSum = levelSums[i];
                maxLevelIndex = i;
            }
        }

        return maxLevelIndex+1;
    }
};