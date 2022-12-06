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

    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path)
    {
        if(root==node) return true;
        if(root->left && getPath(root->left,node,path))
        {
            path.push_back(root->left);
            return true;
        }
        else if(root->right && getPath(root->right,node,path))
        {
            path.push_back(root->right);
            return true;
        }
        else return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        getPath(root,p,pathP);
        getPath(root,q,pathQ);
        pathP.push_back(root);
        pathQ.push_back(root);
        int a = pathP.size(), b = pathQ.size();
        // for(int i=0; i<a; i++) cout<<pathP[i]->val<<endl;
        // cout<<endl;
        // for(int i=0; i<b; i++) cout<<pathQ[i]->val<<endl;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                // cout<<pathP[i]->val<<" "<<pathQ[j]->val<<endl;
                if(pathP[i]==pathQ[j])
                {
                    return pathP[i];
                }
            }
        }
        return NULL;
    }
};