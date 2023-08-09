//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
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
                switch(grid[i][j])
                {
                    case 0:
                    grid[i][j] = -1;
                    break;
                    case 1:
                    grid[i][j] = INT_MAX;
                    break;
                    case 2:
                    q.push({i,j});
                    grid[i][j] = 0;
                    break;
                }
            }
        }
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            for(int k=0; k<4; k++)
            {
                int ni = i + moves[k][0], nj = j + moves[k][1];
                if(ni<0||nj<0||ni>=n||nj>=m||grid[ni][nj]==-1) continue;
                if(grid[i][j]+1<grid[ni][nj])
                {
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni,nj});
                }
            }
            q.pop();
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        ans = max(ans,grid[i][j]);
        return (ans==INT_MAX) ? -1 : ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends