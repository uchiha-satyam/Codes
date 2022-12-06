/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = min(p->val,q->val), qv = max(p->val,q->val);
        while(root->val<pv || root->val>qv)
        {
            if(root->val<pv) root = root->right;
            else root = root->left;
        }
        return root;
    }
};