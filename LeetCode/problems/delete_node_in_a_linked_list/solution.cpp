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
    void deleteNode(ListNode* node) {
        while(node->next)
        {
            node->val = node->next->val;
            if(node->next->next==NULL)
            {
                ListNode* dump = node->next;
                node->next = NULL;
                delete dump;
            }
            else
                node = node->next;
        }
    }
};