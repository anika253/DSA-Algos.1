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
void solve(TreeNode* root, int targetSum, int sum ,vector<int>&ds, vector<vector<int>>&ans)
{
    if(root==NULL)return;
    targetSum-=root->val;
    ds.push_back(root->val);
    if(targetSum ==0 && root->left==NULL && root->right==NULL)
    {
         ans.push_back(ds);
        
    }
    solve(root->left, targetSum , sum , ds, ans);
    solve(root->right , targetSum, sum, ds, ans);
    targetSum+= root->val;
    ds.pop_back();
 


}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>ds;
        int sum = 0;
        solve(root, targetSum, sum,ds , ans);
        return ans; 
    }
};