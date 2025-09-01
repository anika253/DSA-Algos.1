/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*, TreeNode*>mpp;
void markParents(TreeNode*root)
{
    if(!root) return ;
    if(root->left)
    {
        mpp[root->left]= root;
        markParents(root->left);
    }
    if( root->right)
    {
        mpp[root->right]= root;
        markParents(root->right);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          vector<int>ans;
        if(!root)return ans;
        markParents(root);
        unordered_set<int>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis.insert(target->val);
        while(!q.empty())
        {
            int n = q.size();
           
            if(k==0)
            {
                break;
            }
            while(n--)
            {
                TreeNode*curr = q.front();

                q.pop();
                if(curr->left!= NULL && vis.find(curr->left->val)==vis.end())
                {
                    vis.insert(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right!= NULL && vis.find(curr->right->val)==vis.end())
                {
                     vis.insert(curr->right->val);
                    q.push(curr->right);
                }
                if(mpp.find(curr)!= mpp.end() && vis.find(mpp[curr]->val)==vis.end())
                {
                    vis.insert(mpp[curr]->val);
                    q.push(mpp[curr]);
                }
              
            }
            k--;
        }
      
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            ans.push_back(topo->val);
        }return ans;

    }
};