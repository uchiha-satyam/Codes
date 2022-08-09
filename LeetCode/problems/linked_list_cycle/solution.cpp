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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        bool flag = false;
        while(head)
        {
            s.emplace(head);
            if(head->next && s.count(head->next)==1)
            {
                flag = true;
                break;
            }
            head = head->next;
        }
        return flag;
    }
};