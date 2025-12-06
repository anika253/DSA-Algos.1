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
void inorder(TreeNode* root  , vector<int>&final)
{
    if( root==NULL) return;
    inorder( root->left , final);
    final.push_back(root->val);
    inorder(root->right , final);
    
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>final;
          inorder( root,  final);
          return final[k-1];
          
    }
};