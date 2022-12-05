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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        ans.push_back(vector<int>(1,root->val));
        queue<TreeNode*> order;
        order.push(root);
        order.push(NULL);
        vector<int> v;
        while(!order.empty())
        {
            TreeNode* node = order.front();
            order.pop();
            if(node==NULL)
            {
                if(order.empty()) break;
                else
                {
                    order.push(NULL);
                    ans.push_back(v);
                    v.clear();
                    continue;
                }
            }
            if(node->left)
            {
                order.push(node->left);
                v.push_back(node->left->val);
            }
            if(node->right)
            {
                order.push(node->right);
                v.push_back(node->right->val);
            }
        }
        return ans;
    }
};