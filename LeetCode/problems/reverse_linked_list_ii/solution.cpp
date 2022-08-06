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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return head;
        int count = 0;
        vector<ListNode*> vec;
        ListNode* temp = NULL;
        while(count<left-1)
        {
            if(temp==NULL)
                temp = head;
            else
                temp = temp->next;
            count++;
        }
        ListNode* t;
        if(temp==NULL)
            t = head;
        else
            t = temp->next;
        for(int i=left; i<=right; i++)
        {
            vec.push_back(t);
            // cout<<t->val<<" ";
            t = t->next;
        }
        for(int i=right-left; i>=0; i--)
        {
            if(temp==NULL)
            {
                temp = vec[i];
                head = temp;
            }
            else
            {
                temp->next = vec[i];
                temp = temp->next;
            }
        }
        temp->next = t;
        return head;
    }
};