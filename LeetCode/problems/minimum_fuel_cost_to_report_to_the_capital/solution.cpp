class Solution {
    long long bfs(vector<vector<int>>& edge, vector<bool>& visited, int x, int& s,long long& ans)
    {
        visited[x] = true;
        long long num = 1;
        for(int i=0; i<edge[x].size(); i++)
        {
            if(!visited[edge[x][i]])
            {
                long long a = bfs(edge,visited,edge[x][i],s,ans);
                num += a;
                ans += ceil(a/(s*1.0));
            }
        }
        return num;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> edge(n);
        for(int i=0; i<n-1; i++)
        {
            edge[roads[i][0]].push_back(roads[i][1]);
            edge[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> visited(n,false);
        long long ans = 0;
        bfs(edge,visited,0,seats,ans);
        return ans;
    }
};