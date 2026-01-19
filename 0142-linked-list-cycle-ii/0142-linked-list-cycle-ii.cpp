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
    if(head==NULL || head->next ==NULL)return head;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;

}
    ListNode *detectCycle(ListNode *head) {
             if(head==NULL || head->next==NULL)return NULL;
             ListNode*temp= helper(head);
             if(temp==NULL)return NULL;
             ListNode*temp1 = head;
             while(temp1!= temp)
             {
                temp1= temp1->next;
                temp = temp->next;
                
             }
             return temp;
    }
};