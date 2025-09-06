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
bool f(TreeNode*root, long lower, long upper)
{
    if(root== NULL) return true;
    if(root->val > lower && root->val < upper)
    {
      
     bool l = f(root->left, lower,  root->val);
     bool r =  f( root->right , root->val , upper);
     



return l&&r;}
return false;





}

    bool isValidBST(TreeNode* root) {
        if(root== NULL) return true;
        return f(root, LONG_MIN, LONG_MAX);
    }
};