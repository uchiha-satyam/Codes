class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        int64_t dp[m][n];
        int rd = 1, cd = 1;
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                dp[i][j] = 0;
                if(i==m-1)
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        rd = 0;
                    }
                    dp[i][j] = rd;
                    continue;
                }
                if(j==n-1)
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        cd = 0;
                    }
                    dp[i][j] = cd;
                    continue;
                }
                if(obstacleGrid[i][j]==0) dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};