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
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> s, l;
        ListNode* temp = head;
        ListNode* newHead;
        if(head==NULL) return head;
        while(temp)
        {
            if(temp->val < x)
                s.push_back(temp);
            else
                l.push_back(temp);
            temp = temp->next;
        }
        if(s.size())
        {
            newHead = s[0];
            temp = newHead;
            for(int i=1; i<s.size(); i++)
            {
                temp->next = s[i];
                temp = temp->next;
            }
        }
        if(l.size())
        {
            int i = 0;
            if(s.empty())
            {
                newHead = l[0];
                temp = newHead;
                i = 1;
            }
            for(; i<l.size(); i++)
            {
                temp->next = l[i];
                temp = temp->next;
            }
        }
        temp->next = NULL;
        return newHead;
    }
};