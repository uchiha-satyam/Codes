class Solution {
public:

    void getPaths(vector<vector<int>>& ans, vector<vector<bool>>& ad, vector<int> path, int s, int d, vector<bool> visited)
    {
        if(visited[s]==true) return;
        path.push_back(s);
        visited[s] = true;
        int n = visited.size();
        if(s==d)
        {
            ans.push_back(path);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(ad[s][i])
            {
                getPaths(ans,ad,path,i,d,visited);
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> ad(n,vector<bool>(n,false));
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<graph[i].size(); j++)
            {
                ad[i][graph[i][j]] = true;
            }
        }
        vector<int> path;
        vector<bool> visited(n,false);
        getPaths(ans,ad,path,0,n-1,visited);
        return ans;
    }
};