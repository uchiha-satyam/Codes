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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        int length = lists.size();
        if(length==0) return res;
        bool flag = true;
        vector<int> arr;
        for(int i=0; i<length; i++)
        {
            if(lists[i])
            arr.push_back(lists[i]->val);
            else
            arr.push_back(-1);
        }
        while(flag)
        {
            flag = false;
            int minVal = INT_MAX;
            int minP = 0;
            for(int i=0; i<length; i++)
            {
                if(lists[i])
                {
                    flag = true;
                    if(arr[i] < minVal)
                    {
                        minVal = arr[i];
                        minP = i;
                    }
                }
                else
                {
                    flag = flag || false;
                }
            }
            if(lists[minP])
            {
                res = insert(res,minVal);
                lists[minP] = lists[minP]->next;
                if(lists[minP])
                {
                    arr[minP] = lists[minP]->val;
                }
            }
        }
        return res;
    }
    
    ListNode* insert(ListNode* l, int val)
    {
        ListNode* n = new ListNode(val);
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