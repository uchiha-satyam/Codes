//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m));
        // vector<vector<int>> t;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i==n-1&&j==m-1)
                {
                    dp[i][j].push_back(vector<int>(1,grid[i][j]));
                    continue;
                }
                if(i<n-1)
                {
                    for(auto& x : dp[i+1][j])
                    {
                        vector<int> t(1,grid[i][j]);
                        for(auto& y : x)
                        t.push_back(y);
                        dp[i][j].push_back(t);
                    }
                }
                if(j<m-1)
                {
                    for(auto& x : dp[i][j+1])
                    {
                        vector<int> t(1,grid[i][j]);
                        for(auto& y : x)
                        t.push_back(y);
                        dp[i][j].push_back(t);
                    }
                }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends