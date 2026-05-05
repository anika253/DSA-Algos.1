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
ListNode*findNthNode(ListNode*temp, int x)
{
 
    int cnt = x;
    while(temp!= NULL && cnt-1>0)
    {
          temp = temp->next;
          cnt--;
        
    }
    return temp;
}



    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL || k==0) return head;
        ListNode*temp = head;
        int len= 1;
        while(temp->next!=NULL)
        {
            temp= temp->next;
           len++;
        }
        if(k%len==0) return head;
        k = k %len ;
          temp->next = head;
          ListNode* newtail = findNthNode(head, len-k);
          head = newtail->next;
          newtail->next = NULL;
          return head;

        
    }
};