class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int column = triangle[row-1].size();
        int dp[row][column];
        for(int i=row-1; i>=0; i--)
        {
            for(int j=0; j<=i; j++)
            {
                if(i==row-1)
                {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};