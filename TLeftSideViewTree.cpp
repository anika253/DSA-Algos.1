#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode{
    public:
    int val;
 TreeNode*left;
 TreeNode*right;
 public:
 TreeNode(int x)
 {
     this->val = x;
     this->left =NULL;
     this->right = NULL;
 }
    
};
vector<intleftSideView(TreeNode*root)
{
    queue<TreeNode*>q;
    vector<int>ans;
    if(!root)return  ans;
    q.push(root);
while(!q.empty())
{
int n = q.size();
for( int i = 0 ; i<n; i++)
{
auto topo = q.front();
q.pop();
if(i==0)
{
    ans.push_back(topo->val);
}

if(topo->left)
{
    q.push(topo->left);
}
if(topo->right)
{
    q.push(topo->right);
}

}
}
return ans;
}
int main() {
TreeNode*root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left ->right = new TreeNode(5);
root->right->right = new TreeNode(4);
vector<int>finaly = leftSideView(root);
for( int i = 0 ; i<finaly.size(); i++)
{
    cout << finaly[i]<< endl;
}

}
