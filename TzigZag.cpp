#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

vector<vector<int>> ZigZag(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool ltr = true;  // Left to right

    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);  // Resize to hold n elements

        for (int i = 0; i < n; i++) {
            TreeNode* topo = q.front();
            q.pop();

            int ind = ltr ? i : n - 1 - i;
            level[ind] = topo->val;

            if (topo->left) q.push(topo->left);
            if (topo->right) q.push(topo->right);
        }

        ans.push_back(level);
        ltr = !ltr;  // Flip direction
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = ZigZag(root);

    for (auto level : ans) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
