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
    
    void levelOrder(queue<vector<TreeNode*>> &q, vector<vector<int>> &v)
    {
        if(q.size()==0) return;
        vector<TreeNode*> qu = q.front(), nqu;
        vector<int> vec;
        for(int i=0; i<qu.size(); i++)
        {
            TreeNode* root = qu[i];
            if(root->left)
            {
                vec.push_back(root->left->val);
                nqu.push_back(root->left);
            }
            if(root->right)
            {
                vec.push_back(root->right->val);
                nqu.push_back(root->right);
            }
        }
        if(nqu.size())
        {
            q.push(nqu);
            v.push_back(vec);
        }
        q.pop();
        levelOrder(q,v);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<vector<TreeNode*>> q;
        vector<TreeNode*> qu;
        vector<int> vec;
        vector<vector<int>> v;
        if(root==NULL) return v;
        qu.push_back(root);
        vec.push_back(root->val);
        q.push(qu);
        v.push_back(vec);
        levelOrder(q,v);
        return v;
    }
};