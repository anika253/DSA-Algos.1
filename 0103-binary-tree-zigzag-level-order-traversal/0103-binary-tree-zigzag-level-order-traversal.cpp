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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>final;
        if(!root) return final;
        queue<TreeNode*>q;
        q.push(root);
     
        bool ltr = true;
  int ind =-1;
        while(!q.empty())
    {
         int n = q.size();
         vector<int>lvl(n);

       for(int i = 0 ; i<n; i++)
         {
            auto topo = q.front();
            q.pop();
          int ind =-1;
            if(ltr)
            {
                ind =i;
            }
            else{
                ind = n-i-1;
            }
            lvl[ind]= topo->val;
            if(topo->left)
            {
                q.push(topo->left);
            }
            if(topo->right)
            {
                q.push(topo->right);
            }
         }

     final.push_back(lvl);
     ltr = !ltr;


    }
    return final;
    }
};