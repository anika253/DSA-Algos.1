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
 ListNode*help(ListNode*head , int x)
 {
    if(head==NULL)return head;
    ListNode*n = head;
     int c = 0;
    while(n!= NULL && c != x-1)
    {
        n= n->next;
        c++;
    }
    return n;

 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL || k==0)return head;
        int len = 1;
        ListNode*temp = head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
            len++;
        }
        if(k%len==0) return head;
        k = k%len;
        temp->next = head;
        ListNode*newN = help(head , len-k);
        ListNode*nn = newN->next;
        head = nn;
        newN->next = NULL;
        return head;


    }
};