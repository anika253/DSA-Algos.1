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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*list1 = l1;
        ListNode*list2 = l2;
        
        if(list1==NULL )return list2;
        if(list2==NULL)return list1;
        int sum = 0;
        int carry = 0;
        ListNode*dummy = new ListNode(-1);
        ListNode*tail = dummy;
        
        while(l1!= NULL || l2!= NULL || carry!=0)
        {
           sum = carry;
           if(l1!= NULL)
           {
            sum+= l1->val;
            l1 = l1->next;
           }
           if(l2!= NULL)
           {
            sum+= l2->val;
            l2 = l2->next;

           }
           

        
       
        carry = sum/10;
         sum = sum%10;
        ListNode*temp = new ListNode(sum);
        tail->next = temp;
        tail = tail->next;
        }
        return dummy->next;

    }
};