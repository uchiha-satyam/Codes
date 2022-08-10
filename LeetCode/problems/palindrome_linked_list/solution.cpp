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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        vector<ListNode*> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        int s=0, e=vec.size()-1;
        while(s<e)
        {
            if(vec[s]->val!=vec[e]->val) return false;
            s++;
            e--;
        }
        return true;
    }
};