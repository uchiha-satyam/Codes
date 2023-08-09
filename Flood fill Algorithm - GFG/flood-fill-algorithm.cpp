//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n = image.size(), m = image[0].size(), color = image[sr][sc];
        if(newColor==color) return image;
        queue<pair<int,int>> q;
        int moves[4][2] = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        image[sr][sc] = newColor;
        q.push({sr,sc});
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            for(int k=0; k<4; k++)
            {
                int ni = i + moves[k][0], nj = j + moves[k][1];
                if(ni<0||nj<0||ni>=n||nj>=m||image[ni][nj]!=color) continue;
                image[ni][nj] = newColor;
                q.push({ni,nj});
            }
            q.pop();
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends