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
    void goodTraverse(TreeNode* root, int m, int& ans)
    {
        if(root==NULL) return;
        if(root->val>=m) ans++;
        m = max(m,root->val);
        goodTraverse(root->left,m,ans);
        goodTraverse(root->right,m,ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        goodTraverse(root,INT_MIN,ans);
        return ans;
    }
};