/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root== NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                Node* topo = q.front();
                q.pop();
                if(topo->left)
                {
                    q.push(topo->left);

                }
                if(topo->right)
                {
                    q.push(topo->right);
                }
                if(topo->left && topo->right){
                    topo->left->next = topo->right;
                }
                if(topo->next!= NULL && topo->next->left!= NULL)
                {
                    topo->right->next = topo->next->left;
                }
            }
        }
        return root;
    }
};