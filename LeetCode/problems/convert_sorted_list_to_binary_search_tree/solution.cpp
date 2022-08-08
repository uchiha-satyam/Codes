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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* get(vector<int> &vec, int s, int e)
    {
        if(s>e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = get(vec,s,mid-1);
        root->right = get(vec,mid+1,e);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        if(head==NULL) return NULL;
        while(head!=NULL)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        sort(vec.begin(),vec.end());
        return get(vec,0,vec.size()-1);
    }
};