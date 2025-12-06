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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0});
        long long  maxW = 0;
        while(!q.empty())
        {
            auto t = q.front();
            long long l = t.second;
           long long r = q.back().second;
            maxW= max(r-l+1 , maxW);
           
            int n= q.size();
            while(n--)
            {
                long long ind = q.front().second;
                TreeNode*curr = q.front().first;
                q.pop();
                if(curr->left)
                {
                    q.push({curr->left, 2*ind+1});
                }
                if(curr->right)
                {
                    q.push({curr->right , 2*ind+2});
                }

              



            }



        }
        return maxW;
    }
};