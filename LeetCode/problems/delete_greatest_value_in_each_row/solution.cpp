class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
            sort(grid[i].begin(),grid[i].end());
        int ans = 0;
        for(int j=0; j<n; j++)
        {
            int val = INT_MIN;
            for(int i=0; i<m; i++)
                val = max(val,grid[i][j]);
            ans += val;
        }
        return ans;
    }
};