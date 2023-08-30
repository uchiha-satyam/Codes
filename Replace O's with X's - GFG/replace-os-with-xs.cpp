//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> vec(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            if(mat[0][i]=='O') q.push({0,i});
            if(mat[n-1][i]=='O') q.push({n-1,i});
        }
        for(int i=1; i<n-1; i++)
        {
            if(mat[i][0]=='O') q.push({i,0});
            if(mat[i][m-1]=='O') q.push({i,m-1});
        }
        int moves[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vec[x][y] = 'O';
            for(int k=0; k<4; k++)
            {
                int nx = x + moves[k][0];
                int ny = y + moves[k][1];
                if(nx<0||ny<0||nx>=n||ny>=m||mat[nx][ny]=='X'||vec[nx][ny]=='O') continue;
                vec[nx][ny] = 'O';
                q.push({nx,ny});
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends