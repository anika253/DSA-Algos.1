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
unordered_map<TreeNode* , int >mpp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mpp.find(root)!= mpp.end()) return mpp[root];
        int skip = rob(root->left )+rob( root->right);
        int take = root->val;
        if( root->left )
        {
            take+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right)
        {
            take+= rob( root->right->left)+ rob( root->right->right);
        }
       return  mpp[root]=max(skip , take);
    }
};