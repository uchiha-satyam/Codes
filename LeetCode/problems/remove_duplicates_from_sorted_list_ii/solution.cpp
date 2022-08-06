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
        ListNode* newHead = NULL;
        ListNode* temp = head;
        bool flag = false;
        while(prev->next)
        {
            if(prev->val == prev->next->val)
            {
                flag = true;
                ListNode* dump = prev->next;
                prev->next = prev->next->next;
                delete dump;
            }
            else
            {
                if(flag)
                {
                    ListNode* dump = prev;
                    prev = prev->next;
                    if(temp)
                    temp->next = prev;
                    if(dump==temp) temp=NULL;
                    delete dump;
                    flag = false;
                }
                else
                {
                    if(newHead==NULL) newHead = prev;
                    temp = prev;
                    prev = prev->next;
                }
            }
        }
        if(flag)
        {
            if(temp)
            temp->next = NULL;
            delete prev;
            return newHead;
        }
        else if(newHead==NULL) newHead = prev;
        return newHead;
    }
};