//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool help(vector<vector<char>>& grid, string& str, int r, int c, int vx, int vy)
    {
        int n = grid.size(), m = grid[0].size(), s = str.size();
        int x = 0;
        while(r>=0&&c>=0&&r<n&&c<m&&x<s)
        {
            if(grid[r][c]!=str[x]) return false;
            r += vx;
            c += vy;
            x++;
        }
        if(x==s) return true;
        return false;
    }
public:
	vector<vector<int>> searchWord(vector<vector<char>> grid, string word){
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    int s = word.size();
	    vector<vector<int>> ans;
	    int moves[8][2] = {
	        {0,1},
	        {1,1},
	        {1,0},
	        {1,-1},
	        {0,-1},
	        {-1,-1},
	        {-1,0},
	        {-1,1}
	    };
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            for(int k=0; k<8; k++)
	            {
	                if(help(grid,word,i,j,moves[k][0],moves[k][1]))
	                {
	                    ans.push_back({i,j});
	                    break;
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends