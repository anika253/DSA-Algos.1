#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x)
    {
        this->val = x;
        this->left= NULL;
        this->right = NULL;
    }
};
vector<vector<int>>VerticalOrder(TreeNode*root)
{
  vector<vector<int>>ans;
    if(!root) return ans;
    unordered_map<int, vector<int>>mpp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto [node, lvl]= q.front();
        q.pop();
        mpp[lvl].push_back(node->val);
        if(node->left)
        {
            q.push({node->left, lvl-1});
        }
        if(node->right)
        {
            q.push({node->right, lvl+1});
        }
        
        
        
        
    }
    for(auto [nodeV, value]: mpp)
    {
        ans.push_back(value);
    }
    return ans;
}
    
    
    
    
    
    

int main()
{
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->left->right = new TreeNode(4);
     root->right->left = new TreeNode(5);
     root->right->right = new   TreeNode(6);
     vector<vector<int>>ans = VerticalOrder(root);
     for(int i = 0 ; i<ans.size(); i++)
     {
         for(int j = 0 ; j<ans[i].size(); j++)
         {
             cout << ans[i][j]<< " ";
         }
         cout << endl;
     }
     return 0;
    
}
















