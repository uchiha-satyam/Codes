class Solution {
public:
    int numTrees(int n) {
        if(n<3) return n;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
        {
            int count = 0;
            int nodes = i-1;
            for(int j=0; j<=nodes/2; j++)
            count += 2 * dp[j] * dp[nodes - j];
            if(nodes%2==0) count -= dp[nodes/2] * dp[nodes/2];
            dp[i] = count;
        }
        return dp[n];
    }
};