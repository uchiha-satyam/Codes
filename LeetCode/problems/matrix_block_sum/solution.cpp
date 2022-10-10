class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0)), ans(r,vector<int>(c,0));
        for(int i=0; i<r; i++)
        {
            int sum = 0;
            int k1 = min(k,c);
            for(int j=0; j<k1; j++)
            sum += mat[i][j];
            for(int j=0; j<c; j++)
            {
                if(j+k<c)
                sum += mat[i][j+k];
                if(j-k-1>=0)
                sum -= mat[i][j-k-1];
                dp[i][j] = sum;
            }
        }
        for(int j=0; j<c; j++)
        {
            int sum = 0;
            int k2 = min(k,r);
            for(int i=0; i<k2; i++)
            sum += dp[i][j];
            for(int i=0; i<r; i++)
            {
                if(i+k<r)
                sum += dp[i+k][j];
                if(i-k-1>=0)
                sum -= dp[i-k-1][j];
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};