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
TreeNode*helper( vector<int>& preorder, vector<int>& inorder, int &ind , int start , int end)
{
    if( start> end) return NULL;
    int rootval = preorder[ind];
    int  i = start ;
    for( ; i<=end ; i++)
    {
        if(inorder[i]==rootval) break;
       


    }
     ind++;
     TreeNode* root = new TreeNode( rootval);

    root->left = helper( preorder, inorder, ind, start ,i-1);
root->right= helper( preorder, inorder, ind, i+1 ,end);
     return root;

     
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        int n = preorder.size();
        return helper( preorder, inorder, ind, 0 , n-1);

    }
};