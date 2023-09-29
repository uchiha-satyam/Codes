//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]) q.push({i,0});
            if(grid[i][m-1]) q.push({i,m-1});
        }
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]) q.push({0,i});
            if(grid[n-1][i]) q.push({n-1,i});
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        ans += grid[i][j];
        int moves[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(grid[x][y]==2) continue;
            grid[x][y] = 2;
            ans--;
            for(int k=0; k<4; k++)
            {
                int nx = x + moves[k][0];
                int ny = y + moves[k][1];
                if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]==0||grid[nx][ny]==2) continue;
                q.push({nx,ny});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends