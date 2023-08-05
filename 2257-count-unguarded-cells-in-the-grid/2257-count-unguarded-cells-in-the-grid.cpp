class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(auto& x : walls)
            mat[x[0]][x[1]] = -2;
        for(auto& x : guards)
            mat[x[0]][x[1]] = -1;
        for(int i=0; i<m; i++)
        {
            int v = 0;
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==-1) v = 1;
                else if(mat[i][j]==-2) v = 0;
                else mat[i][j] |= v;
            }
            v = 0;
            for(int j=n-1; j>=0; j--)
            {
                if(mat[i][j]==-1) v = 1;
                else if(mat[i][j]==-2) v = 0;
                else mat[i][j] |= v;
            }
        }
        for(int j=0; j<n; j++)
        {
            int v = 0;
            for(int i=0; i<m; i++)
            {
                if(mat[i][j]==-1) v = 1;
                else if(mat[i][j]==-2) v = 0;
                else mat[i][j] |= v;
            }
            v = 0;
            for(int i=m-1; i>=0; i--)
            {
                if(mat[i][j]==-1) v = 1;
                else if(mat[i][j]==-2) v = 0;
                else mat[i][j] |= v;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(mat[i][j]==0) ans++;
        return ans;
    }
};