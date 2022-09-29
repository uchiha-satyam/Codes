class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0;
        // bool dp[n+1];
        // if(n<2) return false;
        // dp[0] = dp[1] = false;
        // cout<<"1 "<<boolalpha<<dp[1]<<endl;
        // for(int i=2; i<=n; i++)
        // {
        //     dp[i] = false;
        //     for(int j=1; j<=sqrt(i); j++)
        //     {
        //         if(i%j==0)
        //         {
        //             dp[i] = dp[i] || !dp[i-j];
        //             if(j!=1) dp[i] = dp[i] || !dp[i-i/j];
        //             if(dp[i]) break;
        //         }
        //     }
        //     cout<<i<<" "<<boolalpha<<dp[i]<<endl;
        // }
        // return dp[n];
    }
};