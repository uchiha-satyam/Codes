//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        cost[n-1][n-1] = grid[n-1][n-1];
        int moves[4][2] = {
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };
        pq.push({cost[n-1][n-1],{n-1,n-1}});
        while(!pq.empty())
        {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(visited[r][c]) continue;
            visited[r][c] = true;
            for(int k=0; k<4; k++)
            {
                int nr = r + moves[k][0];
                int nc = c + moves[k][1];
                if(nr<0||nc<0||nr>=n||nc>=n||val+grid[nr][nc]>=cost[nr][nc]) continue;
                cost[nr][nc] = val + grid[nr][nc];
                pq.push({cost[nr][nc],{nr,nc}});
            }
        }
        return cost[0][0];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends