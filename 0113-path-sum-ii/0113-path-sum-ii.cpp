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
void solve(TreeNode*root, int targetSum , vector<vector<int>>&ans, vector<int>&ds )
{
if( root==NULL)return;
targetSum-=root->val;
ds.push_back(root->val);
if(root->left ==NULL && root->right ==NULL && targetSum==0)
{
    ans.push_back(ds);
    
}

solve( root->left, targetSum , ans, ds);
solve( root->right , targetSum , ans, ds);

targetSum+=root->val;
ds.pop_back();

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>ds;
        if(root==NULL) return ans;
        solve( root, targetSum , ans, ds);
        return ans;
    }
};