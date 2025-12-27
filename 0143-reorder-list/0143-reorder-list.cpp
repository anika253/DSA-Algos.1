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
ListNode* middle(ListNode*head)
{
    if(head==NULL || head->next ==NULL) return head;
    ListNode*slow = head;
    ListNode*fast = head;
    while(fast!= NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode*reverse(ListNode*head)
{
    if(head==NULL || head->next ==NULL) return head;
    ListNode* curr = head;
    ListNode*forw = NULL;
    ListNode*prev = NULL;
    while(curr!= NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;


}


    void reorderList(ListNode* head) {
   if(head==NULL || head->next ==NULL) return;
        ListNode*mid = middle(head);
        if(mid== NULL)return ;
        ListNode*temp = head;
        while(temp->next!= mid)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        ListNode*temp2= mid;
      ListNode*l2 =   reverse(temp2);
ListNode*dummy = new ListNode(-1);
ListNode*fnl = dummy;
ListNode*it1 = head;
ListNode*it2 = l2;
while(it1!= NULL && it2!= NULL)
{
    dummy->next = it1;
    it1= it1->next;
    dummy = dummy->next;
    dummy->next = it2;
    it2 = it2->next;
    dummy = dummy->next;

}
while(it1!= NULL)
{
    dummy->next = it1;
    it1= it1->next;
    dummy = dummy->next;
}
while(it2!= NULL)
{
    dummy->next = it2;
    it2= it2->next;
    dummy = dummy->next;
}

head = fnl->next;

    

        
    }
};