/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode*helper(ListNode*head)
{ if( head==NULL || head->next ==NULL) return NULL;
ListNode*slow = head;
ListNode*fast =head;
while(fast!= NULL && fast->next!= NULL)
{
    fast = fast->next->next;
    slow = slow ->next;
    if(slow==fast) return slow;
}

return slow;

}
    ListNode *detectCycle(ListNode *head) {
        if( head==NULL || head->next ==NULL) return NULL;
        ListNode*inter = helper(head);
        if( inter==NULL)return NULL;
        ListNode*slow = head;
        while(slow!= inter)
        {
            slow =slow->next;
            inter = inter->next;
        }
        if(slow==inter)
        {
            return slow;
        }
        
        return NULL;

    }
};