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
    void get(vector<TreeNode*> &vec, TreeNode* root)
    {
        if(root==NULL) return;
        else vec.push_back(root);
        if(root) get(vec,root->left);
        if(root) get(vec,root->right);
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> vec;
        get(vec,root);
        int i;
        for(i=1; i<vec.size(); i++)
        {
            vec[i-1]->left = NULL;
            vec[i-1]->right = vec[i];
        }
    }
};