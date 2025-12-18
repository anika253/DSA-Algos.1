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
{ if( head==NULL || head->next ==NULL)return NULL;
ListNode*slow = head;
ListNode*fast = head;
    while( fast->next!= NULL)
    {  fast = fast->next->next;
    
        slow = slow->next;
      
        if(slow==fast)return slow;
    }


return NULL;

}
    ListNode *detectCycle(ListNode *head) {
        if( head==NULL || head->next ==NULL)return NULL;

        ListNode*temp = helper(head);
        if(temp==NULL)return NULL;
        ListNode*tmp2 = head;
        while(temp!= tmp2)
        {
            temp= temp->next;
            tmp2 = tmp2->next;
        }    
        return temp;

    }
};