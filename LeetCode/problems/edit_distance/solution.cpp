class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int dp[n1+1][n2+1];
        for(int i=n1; i>=0; i--)
        {
            for(int j=n2; j>=0; j--)
            {
                if(i==n1)
                {
                    dp[i][j] = n2 - j;
                    continue;
                }
                if(j==n2)
                {
                    dp[i][j] = n1 - i;
                    continue;
                }
                if(word1[i]==word2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1])) + 1;
                }
            }
        }
        return dp[0][0];
    }
};