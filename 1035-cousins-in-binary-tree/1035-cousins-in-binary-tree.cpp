class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;

        queue<pair<TreeNode*, TreeNode*>> q; 
        q.push({root, nullptr});

        while (!q.empty()) {
            int n = q.size();
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            for (int i = 0; i < n; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) parentX = parent;
                if (node->val == y) parentY = parent;

                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});
            }

            // both found at same level
            if (parentX && parentY)
                return parentX != parentY; // true if diff parents

            // only one found in this level
            if ((parentX && !parentY) || (!parentX && parentY))
                return false;
        }
        return false;
    }
};
