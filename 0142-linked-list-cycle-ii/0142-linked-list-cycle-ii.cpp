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
{
    if(head==NULL || head->next == NULL) return NULL;
    ListNode*slow = head;
    ListNode*fast = head;
    while(fast!= NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast)return slow;
    }
    return NULL;

}
    ListNode *detectCycle(ListNode *head) {
        if(head ==NULL || head->next==NULL)return NULL;
        ListNode*temp1 = helper(head);
        if(temp1==NULL) return NULL;
        ListNode*temp2 = head;
        while(temp1!= temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
         
        }
return temp1;
    }

};