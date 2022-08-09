/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head)
        {
            s.emplace(head);
            if(head->next&&s.count(head->next))
            {
                return head->next;
            }
            head = head->next;
        }
        return NULL;
    }
};