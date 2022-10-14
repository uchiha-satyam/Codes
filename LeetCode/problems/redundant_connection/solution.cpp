class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans(2);
        int parent[n+1];
        for(int i=1; i<=n; i++)
        {
            parent[i] = i;
        }
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int x = u, y = v;
            while(parent[x]!=x) x = parent[x];
            while(parent[y]!=y) y = parent[y];
            if(x==y)
            {
                ans[0] = u;
                ans[1] = v;
            }
            else
            {
                parent[x] = y;
            }
        }
        return ans;
    }
};