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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = NULL;
        ListNode* fast = head;
        while(fast->next)
        {
            fast = fast->next;
            if(fast->next)
            fast = fast->next;
            if(slow==NULL) slow = head;
            else slow = slow->next;
        }
        if(slow==NULL)
        {
            if(head->next)
            {
                slow = head;
                head = head->next;
                delete slow;
                return head;
            }
            delete head;
            return NULL;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        return head;
    }
};