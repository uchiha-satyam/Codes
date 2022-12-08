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

    void leaf(vector<int>& arr, TreeNode* root)
    {
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL)
        {
            arr.push_back(root->val);
            return;
        }
        if(root->left) leaf(arr,root->left);
        if(root->right) leaf(arr,root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        leaf(l1,root1);
        leaf(l2,root2);
        if(l1.size()==l2.size())
        {
            for(int i=0; i<l1.size(); i++)
            {
                if(l1[i]!=l2[i]) return false;
            }
            return true;
        }
        return false;
    }
};