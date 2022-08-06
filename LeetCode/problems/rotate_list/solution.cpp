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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=1;
        if(head==NULL) return head;
        ListNode* temp = head;
        while(temp->next)
        {
            count++;
            temp = temp->next;
        }
        temp->next = head;
        int s = count - k%count + 1;
        if(s>count) s-=count;
        temp = head;
        for(int i=1; i<s; i++)
        {
            head = head->next;
            temp = temp->next;
        }
        for(int i=1; i<count; i++)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};