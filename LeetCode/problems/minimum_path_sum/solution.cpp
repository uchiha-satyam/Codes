class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                dp[i][j] = 0;
                if(i<m-1 && j<n-1)
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]);
                else if(i<m-1)
                dp[i][j] = dp[i+1][j];
                else if(j<n-1)
                dp[i][j] = dp[i][j+1];
                dp[i][j] += grid[i][j];
            }
        }
        return dp[0][0];
    }
};