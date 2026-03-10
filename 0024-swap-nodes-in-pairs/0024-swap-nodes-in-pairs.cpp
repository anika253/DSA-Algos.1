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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next ==NULL)return head;
        ListNode*curr = head;
        ListNode*forw= NULL;
        ListNode*prev= NULL;
        int k=2;
        int cnt = 0;
        while(cnt<k)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            cnt++;
        }
        if(curr)
        {
            head->next= swapPairs(curr);
        }
        return prev;
    }
};