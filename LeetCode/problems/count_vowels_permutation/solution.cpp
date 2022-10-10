class Solution {
public:
    int countVowelPermutation(int n) {
        int64_t mod = 1e9 + 7;
        int64_t d[5][5] = {
            {0,1,0,0,0},
            {1,0,1,0,0},
            {1,1,0,1,1},
            {0,0,1,0,1},
            {1,0,0,0,0}
        };
        int64_t dp[5][n+1];
        for(int64_t j=0; j<=n; j++)
        {
            for(int64_t i=0; i<5; i++)
            {
                if(j==0||j==1)
                {
                    dp[i][j] = j;
                    continue;
                }
                dp[i][j] = 0;
                for(int64_t x=0; x<5; x++)
                {
                    dp[i][j] += dp[x][j-1] * d[x][i];
                }
                dp[i][j] = dp[i][j]%mod;
            }
        }
        int64_t ans = 0;
        for(int64_t i=0; i<5; i++)
        ans += dp[i][n];
        return (int)(ans%mod);
    }
};