class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int dp[row][column+2];
        for(int i=row-1; i>=0; i--)
        {
            for(int j=0; j<=column+1; j++)
            {
                if(j==0||j==column+1)
                {
                    dp[i][j] = INT_MAX;
                    continue;
                }
                if(i==row-1)
                {
                    dp[i][j] = matrix[i][j-1];
                    continue;
                }
                dp[i][j] = matrix[i][j-1] + min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
            }
        }
        int ans = INT_MAX;
        for(int i=1; i<=column; i++)
        ans = min(ans,dp[0][i]);
        return ans;
    }
};