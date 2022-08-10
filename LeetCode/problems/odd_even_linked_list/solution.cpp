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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<ListNode*> o, e;
        int i=1;
        while(head)
        {
            if(i%2==1) o.push_back(head);
            else e.push_back(head);
            head = head->next;
            i++;
        }
        head = o[0];
        if(o.size()==1) return head;
        for(i=0; i<o.size()-1; i++)
        {
            o[i]->next = o[i+1];
        }
        if(e.size()) o.back()->next = e[0];
        for(i=0; i<e.size()-1; i++)
        {
            e[i]->next = e[i+1];
        }
        if(e.size()) e.back()->next = NULL;
        return head;
    }
};