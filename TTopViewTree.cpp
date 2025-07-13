#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue>
using namespace std;
class TreeNode {        
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x) {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }   
};
vector<int>TopView(TreeNode*root)
{
    vector<int>ans;
    if(!root)
    {
        return ans;
    }
    
    unordered_map<int, int>levVal;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
       auto[node, lvl] = q.front();
        q.pop();
      
        
            if(levVal.find(lvl)==levVal.end())
            {
                levVal[lvl]= node->val;
            }
            
            
            if(node->left)
            {
                q.push({node->left, lvl-1});
                
            }
            if(node->right)
            {
                q.push({node->right, lvl+1});
            }
        
  
    }
    for(auto &[lvll, val]:levVal)
    {
        ans.push_back(val);
    }
    
    
    
    
    
    
    
return ans;
    
}
int main() {
TreeNode*root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left ->right = new TreeNode(5);
root->right->right = new TreeNode(4);
vector<int>finaly =TopView(root);
for( int i = 0 ; i<finaly.size(); i++)
{
    cout << finaly[i]<< endl;
}

}
