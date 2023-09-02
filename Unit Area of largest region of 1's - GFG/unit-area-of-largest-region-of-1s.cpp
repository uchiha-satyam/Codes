//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int moves[8][2] = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1},
            {1,-1},
            {-1,1},
            {1,1},
            {-1,-1}
        };
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0) continue;
                if(vis[i][j])
                {
                    ans = max(ans,vis[i][j]);
                    continue;
                }
                int c = 1;
                vis[i][j] = c++;
                ans = max(ans,vis[i][j]);
                q.push({i,j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<8; k++)
                    {
                        int nx = x + moves[k][0];
                        int ny = y + moves[k][1];
                        if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]==0||vis[nx][ny]) continue;
                        vis[nx][ny] = c++;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends