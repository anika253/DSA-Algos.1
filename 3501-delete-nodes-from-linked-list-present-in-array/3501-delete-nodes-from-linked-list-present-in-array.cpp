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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

       set<int>s;
       for( auto it: nums)
       {
        s.insert(it);
       }
       ListNode*dummy = new ListNode(-1);
       dummy ->next = head;
      ListNode*curr = head;
      ListNode*prev = dummy;
      while(curr!= NULL)
      {
        if(s.find(curr->val)!= s.end())
        {
            prev->next = curr->next;
                ListNode*del = curr;
                curr = curr->next;
              
        }
        else{
            prev= curr;
            curr = curr->next;
        }
      }
      ListNode*newH = dummy->next;
      delete dummy;
      return newH;

        
    }
};