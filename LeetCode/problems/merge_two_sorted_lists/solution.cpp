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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head, * tail;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1)
        {
            while(list1)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
        }
        else
        {
            while(list2)
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        return head;
    }
};