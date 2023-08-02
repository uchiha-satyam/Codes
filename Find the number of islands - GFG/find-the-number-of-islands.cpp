//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    void dfs(map<pair<int,int>,vector<pair<int,int>>>& mp, set<pair<int,int>>& unvisited, pair<int,int> node)
    {
        if(!unvisited.count(node)) return;
        unvisited.erase(node);
        for(auto& x : mp[node])
        {
            dfs(mp,unvisited,x);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        map<pair<int,int>,vector<pair<int,int>>> mp;
        set<pair<int,int>> unvisited;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    unvisited.insert({i,j});
                    if(i-1>=0&&grid[i-1][j]=='1') mp[{i,j}].push_back({i-1,j});
                    if(i+1<grid.size()&&grid[i+1][j]=='1') mp[{i,j}].push_back({i+1,j});
                    if(j-1>=0&&grid[i][j-1]=='1') mp[{i,j}].push_back({i,j-1});
                    if(j+1<grid[0].size()&&grid[i][j+1]=='1') mp[{i,j}].push_back({i,j+1});
                    
                    if(i-1>=0&&j-1>=0&&grid[i-1][j-1]=='1') mp[{i,j}].push_back({i-1,j-1});
                    if(i-1>=0&&j+1<grid[0].size()&&grid[i-1][j+1]=='1') mp[{i,j}].push_back({i-1,j+1});
                    if(i+1<grid.size()&&j-1>=0&&grid[i+1][j-1]=='1') mp[{i,j}].push_back({i+1,j-1});
                    if(i+1<grid.size()&&j+1<grid[0].size()&&grid[i+1][j+1]=='1') mp[{i,j}].push_back({i+1,j+1});
                }
            }
        }
        int ans = 0;
        while(!unvisited.empty())
        {
            ans++;
            pair<int,int> node = *(unvisited.begin());
            dfs(mp,unvisited,node);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends