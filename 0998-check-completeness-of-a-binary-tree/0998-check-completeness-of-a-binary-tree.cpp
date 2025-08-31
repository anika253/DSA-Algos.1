class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                seenNull = true; 
            } else {
                if (seenNull) return false; // violation
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
