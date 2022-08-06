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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* prev = head;
        while(prev->next)
        {
            if(prev->next->val==prev->val)
            {
                ListNode* dump = prev->next;
                prev->next = prev->next->next;
                delete dump;
            }
            else
            {
                prev = prev->next;
            }
        }
        return head;
    }
};