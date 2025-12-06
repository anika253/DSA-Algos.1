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
bool solve( TreeNode*p , TreeNode*q)
{
    if(p==NULL && q==NULL )return 1;
  if(p==NULL || q==NULL)return 0;
  if(p->val!= q->val)return 0;
  bool x = solve(p->left , q->right);
  bool y = solve(p->right , q->left);
  return x&&y;
}
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return solve(root->left, root->right);
    }
};