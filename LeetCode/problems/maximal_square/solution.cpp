class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int maxSqr = 0;
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int val = matrix[i][j] - '0';
                if(i==m-1 || j==n-1)
                dp[i][j] = val;
                else
                dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1])) * val + val;
                maxSqr = max(maxSqr,dp[i][j]);
            }
        }
        return maxSqr*maxSqr;
    }
};