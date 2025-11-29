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
int cnt(ListNode*head)
{
    if(head==NULL)return 0;
    int cnt = 0;
    ListNode*temp = head;
    while(temp!= NULL)
    {
        temp= temp->next;
        cnt++;
    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int len = cnt(head);
        int node_D = len-n+1;
        if(node_D==1)
        {
            ListNode*temp= head;
            head = head->next;
            temp->next=NULL;
          
            delete temp;
           return head;
        }
       else{
        ListNode*temp = head;
        ListNode*dummy = new ListNode(-1);
        for( int i = 1 ; i<node_D-1 ; i++)
        {
            temp = temp->next;
           


        }
        dummy = temp->next;
      temp->next= dummy->next;
      delete dummy;
      

        

            }












       return head;

       
    }
};