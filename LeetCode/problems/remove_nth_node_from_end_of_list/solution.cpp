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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* req = NULL;
        for(int i=1; i<n; i++)
        {
            temp = temp->next;
        }
        if(temp->next)
        {
            temp = temp->next;
            req = head;
        }
        while(temp->next)
        {
            temp = temp->next;
            req = req->next;
        }
        if(req)
        {
            temp = req->next;
            req->next = req->next->next;
            delete temp;
        }
        else
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
};