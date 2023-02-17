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
    void get(TreeNode* root, vector<int>& values)
    {
        if(root==NULL) return;
        get(root->left,values);
        values.push_back(root->val);
        get(root->right,values);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        get(root,values);
        int diff = INT_MAX;
        for(int i=1; i<values.size(); i++)
        {
            diff = min(diff,values[i]-values[i-1]);
        }
        return diff;
    }
};