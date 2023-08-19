//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void traverse(vector<vector<int>>& matrix, int& n, int& m, int r, int c, int moves[4][2], vector<vector<bool>>& visited, int d, int& ans, int& xd, int& yd)
    {
        if(r==xd&&c==yd)
        {
            ans = max(ans,d);
            return;
        }
        visited[r][c] = true;
        d++;
        for(int k=0; k<4; k++)
        {
            int nr = r + moves[k][0];
            int nc = c + moves[k][1];
            if(nr<0||nc<0||nr>=n||nc>=m||matrix[nr][nc]==0||visited[nr][nc]) continue;
            traverse(matrix,n,m,nr,nc,moves,visited,d,ans,xd,yd);
        }
        visited[r][c] = false;
    }
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int n = matrix.size(), m = matrix[0].size();
        int moves[4][2] = {
            {0,-1},
            {-1,0},
            {0,1},
            {1,0}
        };
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans = INT_MIN;
        if(matrix[xs][ys]==0||matrix[xd][yd]==0) return -1;
        traverse(matrix,n,m,xs,ys,moves,visited,0,ans,xd,yd);
        if(ans==INT_MIN) return -1;
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
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends