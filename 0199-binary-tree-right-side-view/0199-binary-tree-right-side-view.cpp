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
    vector<int> rightSideView(TreeNode* root) {
      vector<int>final;
      if( root==NULL) return final;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty())
      {
        int n = q.size();
       for ( int i = 0 ; i<n;i++)
        {
                 auto topo = q.front();
                 q.pop();
            if(i==n-1)
            {
                final.push_back(topo->val);
            }
            if(topo->left)
            {
                q.push( topo->left);
            }
            if(topo->right)
            {
                q.push(topo->right);
            }
        }
      }
      return final;

    }
};