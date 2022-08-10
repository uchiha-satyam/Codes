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
    ListNode* insertionSortList(ListNode* head) {
        vector<pair<int,ListNode*>> vec;
        if(head==NULL) return head;
        while(head)
        {
            vec.push_back(make_pair(head->val,head));
            head = head->next;
        }
        sort(vec.begin(), vec.end());
        head = vec[0].second;
        ListNode* temp = head;
        for(int i=1; i<vec.size(); i++)
        {
            head->next = vec[i].second;
            head = head->next;
        }
        head->next = NULL;
        return temp;
    }
};