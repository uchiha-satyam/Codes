//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    bool bt(int grid[N][N], vector<unordered_set<int>>& row, vector<unordered_set<int>>& col, vector<vector<unordered_set<int>>>& sub, int pos)
    {
        if(pos>=N*N) return true;
        int r = pos/N, c = pos%N;
        if(grid[r][c]!=0) return bt(grid,row,col,sub,pos+1);
        bool flag = false;
        for(int i=1; i<=N; i++)
        {
            if(row[r].count(i)||col[c].count(i)||sub[r/3][c/3].count(i)) continue;
            grid[r][c] = i;
            row[r].insert(i);
            col[c].insert(i);
            sub[r/3][c/3].insert(i);
            flag = bt(grid,row,col,sub,pos+1);
            if(flag) return flag;
            sub[r/3][c/3].erase(i);
            col[c].erase(i);
            row[r].erase(i);
            grid[r][c] = 0;
        }
        return flag;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        vector<unordered_set<int>> row(N), column(N);
        vector<vector<unordered_set<int>>> sub(N/3,vector<unordered_set<int>>(N/3));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(grid[i][j]==0) continue;
                row[i].insert(grid[i][j]);
                column[j].insert(grid[i][j]);
                sub[i/3][j/3].insert(grid[i][j]);
            }
        }
        bool ans = bt(grid,row,column,sub,0);
        return ans;
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cout<<grid[i][j]<<" ";
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends