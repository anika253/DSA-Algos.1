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
int solve(TreeNode*root , int &diam)
{
    if(root==NULL)return 0;
    int l = solve(root->left, diam);
    int r = solve(root->right , diam);
    diam = max( diam , l+r);
    return max(l , r)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int diam = 0;
        solve( root, diam);
        return diam;

    }
};