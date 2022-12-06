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
public:

    int get(TreeNode* root,int minimum, int maximum)
    {
        if(root==NULL) return abs(maximum-minimum);
        minimum = min(minimum,root->val);
        maximum = max(maximum,root->val);
        return max(get(root->left,minimum,maximum),get(root->right,minimum,maximum));
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = get(root,INT_MAX,INT_MIN);
        return ans;
    }
};