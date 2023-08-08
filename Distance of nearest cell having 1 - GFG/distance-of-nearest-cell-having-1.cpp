//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j]==0) grid[i][j] = INT_MAX-1;
	            else grid[i][j] = 0;
	        }
	    }
	    for(int k=0; k<2; k++)
	    {
	        for(int i=0; i<n; i++)
    	    {
    	        for(int j=0; j<m; j++)
    	        {
    	            if(j==0) continue;
    	            grid[i][j] = min(grid[i][j],grid[i][j-1]+1);
    	        }
    	    }
    	    for(int j=0; j<m; j++)
    	    {
    	        for(int i=0; i<n; i++)
    	        {
    	            if(i==0) continue;
    	            grid[i][j] = min(grid[i][j],grid[i-1][j]+1);
    	        }
    	    }
    	    for(int i=0; i<n; i++)
    	    {
    	        for(int j=m-1; j>=0; j--)
    	        {
    	            if(j==m-1) continue;
    	            grid[i][j] = min(grid[i][j],grid[i][j+1]+1);
    	        }
    	    }
    	    for(int j=m-1; j>=0; j--)
    	    {
    	        for(int i=n-1; i>=0; i--)
    	        {
    	            if(i==n-1) continue;
    	            grid[i][j] = min(grid[i][j],grid[i+1][j]+1);
    	        }
    	    }
	    }
	    return grid;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends