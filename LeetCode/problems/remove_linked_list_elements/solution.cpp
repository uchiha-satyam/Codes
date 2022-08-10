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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
        {
            ListNode* dump = head;
            head = head->next;
            delete dump;
        }
        ListNode* temp = head;
        while(temp && temp->next)
        {
            if(temp->next->val==val)
            {
                ListNode* dump = temp->next;
                temp->next = temp->next->next;
                delete dump;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};