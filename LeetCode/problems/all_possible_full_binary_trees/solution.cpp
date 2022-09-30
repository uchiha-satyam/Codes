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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        TreeNode* tn = new TreeNode();
        dp[1].push_back(tn);
        for(int i=3; i<=n; i+=2)
        {
            for(int j=1; j<i; j+=2)
            {
                for(auto &x : dp[j])
                {
                    for(auto &y : dp[i-1-j])
                    {
                        TreeNode* t = new TreeNode(0,x,y);
                        dp[i].push_back(t);
                    }
                }
            }
        }
        return dp[n];
    }
};