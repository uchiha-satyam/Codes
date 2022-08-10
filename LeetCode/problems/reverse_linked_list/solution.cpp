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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<ListNode*> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        for(int i=vec.size()-1; i>0; i--)
        {
            vec[i]->next = vec[i-1];
        }
        vec[0]->next = NULL;
        return vec.back();
    }
};