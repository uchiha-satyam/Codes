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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* start=NULL;
        ListNode* s=head, * e=head, * prev=NULL;
        while(s)
        {
            int c=0;
            while(e&&c<k-1)
            {
                e = e->next;
                c++;
            }
            if(e==NULL) break;
            if(prev) prev->next = e;
            ListNode* temp = e->next;
            ListNode* t = s;
            prev = s;
            while(s!=e)
            {
                t = s->next;
                s->next = temp;
                temp = s;
                s = t;
            }
            s->next = temp;
            if(start==NULL) start = s;
                // ListNode* n=start;
                // while(n)
                // {
                //     cout<<n->val<<"->";
                //     n = n->next;
                // }
                // cout<<"NULL"<<endl;
            c=0;
            while(s&&c<k)
            {
                // cout<<e->val<<" ";
                s = s->next;
                e = e->next;
                c++;
            }
        }
        return start;
    }
};