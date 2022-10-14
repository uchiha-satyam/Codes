class Solution {
public:

    void dfs(vector<vector<int>>& ad, vector<bool>& visited, int s)
    {
        visited[s] = true;
        for(int i=0; i<ad[s].size(); i++)
        {
            if(!visited[ad[s][i]])
            dfs(ad,visited,ad[s][i]);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> ad(n);
        int count = 0;
        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(ad,visited,i);
            }
        }
        return count-1;
    }
};