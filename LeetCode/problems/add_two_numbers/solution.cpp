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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem=0;
        ListNode* temp = new ListNode();
        ListNode* l3 = NULL;
        while(l1 || l2)
        {
            int sum = l1->val + l2->val + rem;
            if(sum<10)
            {
                rem = 0;
                l3 = insert(l3,sum);
            }
            else
            {
                rem = 1;
                sum = sum%10;
                l3 = insert(l3,sum);
            }
            l1 = l1->next;
            l2 = l2->next;
            if(l1 && !l2)
            {
                l2 = temp;
            }
            else if(l2 && !l1)
            {
                l1 = temp;
            }
        }
        if(rem == 1)
        {
            l3 = insert(l3,1);
        }
        return l3;
        
    }
    ListNode* insert(ListNode* l, int val)
    {
        ListNode* n = new ListNode(val,NULL);
        if(l==NULL)
        {
            l = n;
            return l;
        }
        ListNode* temp = l;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = n;
        return l;
    }
};