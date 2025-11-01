/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Step 1: Find target node (BFS)
    TreeNode* findT(TreeNode* root, int start) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start)
                return node;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return nullptr;
    }

 
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;

        TreeNode* target = findT(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;

        int time = -1;

        while (!q.empty()) {
            int n = q.size();
            time++;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // Right child
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // Parent
                if (parent.find(curr) != parent.end() && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }

        return time;
    }
};
