//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        int moves[4][2] = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    for(int k=0; k<4; k++)
                    {
                        int ni = i + moves[k][0];
                        int nj = j + moves[k][1];
                        if(ni<0||nj<0||ni>=n||nj>=m) continue;
                        dp[ni][nj] = -1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        if(dp[i][m-1]!=-1)
        {
            dp[i][m-1] = 1;
            q.push({i,m-1});
        }
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nr = r + moves[i][0];
                int nc = c + moves[i][1];
                if(nr<0||nc<0||nr>=n||nc>=m||mat[nr][nc]==-1) continue;
                if(dp[r][c]+1<dp[nr][nc])
                {
                    dp[nr][nc] = dp[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        if(dp[i][0]!=-1) ans = min(ans,dp[i][0]);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends