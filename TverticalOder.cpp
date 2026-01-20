#include <iostream>
#include <vector>
#include <map>
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

vector<vector<int>> VerticalOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    if (!root) return ans;

    map<int, vector<int>> mpp;   // ordered
    queue<pair<TreeNode*, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode*, int> temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int lvl = temp.second;

        mpp[lvl].push_back(node->val);

        if (node->left)
            q.push(make_pair(node->left, lvl - 1));

        if (node->right)
            q.push(make_pair(node->right, lvl + 1));
    }

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = VerticalOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
