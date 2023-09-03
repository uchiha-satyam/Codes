//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int c = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int moves[4][2] = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='O'||vis[i][j]) continue;
                c++;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(vis[x][y]) continue;
                    vis[x][y] = true;
                    for(int k=0; k<4; k++)
                    {
                        int nx = x + moves[k][0];
                        int ny = y + moves[k][1];
                        if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='O'||vis[nx][ny]) continue;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends