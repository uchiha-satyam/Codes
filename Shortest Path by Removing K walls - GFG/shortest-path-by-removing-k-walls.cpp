//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        int moves[4][2] = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        queue<vector<int>> q;
        // q.push({0,0,0,k});
        q.push({0,0});
        vector<vector<vector<int>>> visited(n,vector<vector<int>>(m,{INT_MAX,0,0}));
        visited[0][0] = {0,k-mat[0][0],0};
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            // int d = q.front()[2] + 1;
            // int r = q.front()[3];
            int d = visited[x][y][0] + 1;
            int r = visited[x][y][1];
            q.pop();
            if(r<0||visited[x][y][2]) continue;
            visited[x][y][2] = 1;
            // if(d!=(visited[x][y][0]+1)||r!=visited[x][y][1]) continue;
            for(int i=0; i<4; i++)
            {
                int nx = x + moves[i][0];
                int ny = y + moves[i][1];
                if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny][0]<d) continue;
                // if(mat[nx][ny]==1&&r<=0) continue;
                if(visited[nx][ny][0]==d)
                {
                    visited[nx][ny][1] = max(visited[nx][ny][1],r - mat[nx][ny]);
                }
                else
                {
                    visited[nx][ny][0] = d;
                    visited[nx][ny][1] = r - mat[nx][ny];
                }
                // q.push({nx,ny,visited[nx][ny][0],visited[nx][ny][1]});
                q.push({nx,ny});
            }
        }
        if(visited[n-1][m-1][0]==INT_MAX) return -1;
        return visited[n-1][m-1][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends