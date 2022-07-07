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
    
    TreeNode* buildTreePost(vector<int> &p, vector<int> &i, int ps, int pe, int is, int ie)
    {
        if(pe-ps<0) return NULL;
        TreeNode* root = new TreeNode(p[pe]);
        int ri = 0;
        while(i[ri]!=root->val) ri++;
        int lps=ps, rps;
        int lpe, rpe=pe-1;
        int lis=is, ris=ri+1;
        int lie=ri-1, rie=ie;
        lpe = lps + (lie-lis);
        rps = rpe - (rie-ris);

        root->left = buildTreePost(p,i,lps,lpe,lis,lie);
        root->right = buildTreePost(p,i,rps,rpe,ris,rie);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int s = postorder.size();
        if(s != inorder.size() || s==0) return NULL;
        return buildTreePost(postorder,inorder,0,s-1,0,s-1);
    }
};