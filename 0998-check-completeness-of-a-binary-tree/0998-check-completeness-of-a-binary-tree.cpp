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
int count(TreeNode*root)
{
    if(!root){return 0;}
    return 1+count(root->left)+count(root->right);
}
bool check(TreeNode*root, int ind, int totalN)
{
    if(!root) return true;
    
    if(ind>=totalN ) return false;
    bool left = check(root->left, 2*ind+1, totalN);
    bool right = check(root->right , 2*ind+2, totalN);
    return left && right;
}




    bool isCompleteTree(TreeNode* root) {
         int ind = 0;
         int totalN= count(root);
         return check(root, ind, totalN);
        
    }
};