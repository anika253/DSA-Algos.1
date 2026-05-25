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
ListNode*reverse(ListNode*head)
{
    if(head==NULL || head->next==NULL)return head;
    ListNode*prev=NULL;
    ListNode*forw = NULL;
    ListNode*curr = head;
    while(curr!= NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forw;
    }
    return prev;

}
ListNode*middle(ListNode*head)
{
    if(head==NULL || head->next==NULL)return head;
    ListNode*slow= head;
    ListNode*fast = head;
    
    while(fast->next!= NULL && fast->next->next!= NULL )
    {
       fast = fast->next->next;
       slow = slow->next;
    }
    return slow;

}

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next ==NULL) return true;
        ListNode*mid = middle(head);
        ListNode*temp= reverse(mid->next);
        ListNode*list1 = head;
        ListNode*list2 = temp;
        while(list1!= NULL)
        {
            if(list1->val != list2->val)
       {
        return false;
       }
       list1= list1->next;
       list2 = list2->next;
        }
        ListNode*rev2 = reverse(temp);
        return true;


    }
};