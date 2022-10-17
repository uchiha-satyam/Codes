class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        int dp[n1+1][n2+1];
        for(int i=n1; i>=0; i--)
        {
            for(int j=n2; j>=0; j--)
            {
                if(i==n1 || j==n2)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(text1[i]==text2[j])
                {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};