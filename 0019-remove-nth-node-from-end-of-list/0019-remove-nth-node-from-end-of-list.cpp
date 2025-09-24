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
int helper(ListNode*head)
{
    if(head==NULL)return 0;
    int cnt = 0;
    ListNode*temp = head;
    while(temp!= NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int l = helper(head);
        int final = l-n+1;
        ListNode*temp = head;
          ListNode*temp2= head;
          ListNode*prev= NULL;
        if(final==1)
        {
            head= head->next;
            temp->next = NULL;
            return head;


        }
        else{
           
            while(cnt <final && temp2->next!= NULL)
            {
             prev= temp;
             temp = temp->next;
             cnt++;

            }
            prev->next = tempe2->next;
            temp2->next = NULL;
            delete temp;

        }
        return head;
        
    }
};