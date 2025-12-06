/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
struct comp{
bool operator()(ListNode*a, ListNode*b)
{
    return a->val> b->val;
}
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n= lists.size();
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;
        for( int i = 0; i<n ; i++)
        {
            if(lists[i])
            {
                pq.push(lists[i]);
            }
        }
              ListNode*head = new ListNode(-1);
                ListNode*tail = head;
        while(!pq.empty())
        {
           
          
            auto topo = pq.top();
            pq.pop();
            tail->next = topo;
            tail = tail->next;
            if( topo->next)
            {
                pq.push(topo->next);
            }

        }
        return head->next;
    }
};