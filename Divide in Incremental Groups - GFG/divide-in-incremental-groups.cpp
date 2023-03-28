//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        // Code here
        N -= K;
        int dp[N+1][K][N+1] = {0};
        for(int i=0; i<K; i++)
        {
            dp[0][i][0] = 1;
        }
        for(int n=1; n<=N; n++)
        {
            for(int k=K-1; k>=0; k--)
            {
                int sum = 0;
                for(int s=n; s>=0; s--)
                {
                    if(k==K-1)
                    {
                        if(n>=s)
                        {
                            dp[n][k][s] = 1;
                        }
                        else
                        {
                            dp[n][k][s] = 0;
                        }
                    }
                    else
                    {
                        if(n-s>=s)
                        {
                            sum += dp[n-s][k+1][s];
                        }
                        dp[n][k][s] = sum;
                        // for(int i=s; i<=n; i++)
                        // {
                        //     if(n-i<i) dp[n][k][s] += 0;
                        //     else
                        //     {
                        //         dp[n][k][s] += dp[n-i][k+1][i];
                        //     }
                        // }
                    }
                }
            }
        }
        return dp[N][0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends