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
bool validate(TreeNode*root , long long min , long long max)
{
    if(root==NULL)return true;
    if(root->val > min && root->val <max)
    {
        bool l = validate(root->left, min , root->val);
   bool r = validate(root-> right , root->val, max);
   return l&&r;

    }
    return false;

}
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return validate(root,LONG_MIN , LONG_MAX);

    }
};