class Solution {
    void dfs(vector<pair<vector<int>,vector<int>>>& v, vector<vector<bool>> visited, int& minDist, int& n, int x, int t, int c, int currD)
    {
        visited[c][x] = true;
        // cout<<x<<"->";
        if(x==t)
        {
            minDist = min(minDist,currD);
            // cout<<endl;
            return;
        }
        vector<int>& edge = (c) ? v[x].second : v[x].first;
        for(int i=0; i<edge.size(); i++)
        {
            if(!visited[(c+1)%2][edge[i]])
            dfs(v,visited,minDist,n,edge[i],t,(c+1)%2,currD+1);
        }
        // cout<<endl;
    }
    void bfs(vector<pair<vector<int>,vector<int>>>& v, vector<vector<bool>> visited, vector<int>& ans, int c, int currD)
    {
        queue<int> q;
        // c = (c+1)%2;
        q.push(0);
        q.push(-1);
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            if(f==-1)
            {
                if(q.empty()) return;
                q.push(-1);
                currD++;
                c = (c+1)%2;
                // cout<<"NULL"<<endl;
                continue;
            }
            visited[c][f] = true;
            ans[f] = min(ans[f],currD);
            // cout<<f<<"->"<<ans[f]<<endl;
            vector<int>& edge = (c) ? v[f].second : v[f].first;
            for(int i=0; i<edge.size(); i++)
            {
                // cout<<"("<<edge[i]<<")"<<endl;
                if(!visited[(c+1)%2][edge[i]])
                q.push(edge[i]);
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,INT_MAX);
        vector<pair<vector<int>,vector<int>>> v(n);
        for(int i=0; i<redEdges.size(); i++)
        {
            v[redEdges[i][0]].first.push_back(redEdges[i][1]);
        }
        for(int i=0; i<blueEdges.size(); i++)
        {
            v[blueEdges[i][0]].second.push_back(blueEdges[i][1]);
        }
        // for(int i=0; i<v[0].second.size(); i++)
        // cout<<v[0].second[i]<<endl;
        vector<vector<bool>> visited(2,vector<bool>(n,false));
        for(int i=0; i<2; i++)
        bfs(v,visited,ans,i,0);
        for(int i=0; i<n; i++)
        if(ans[i]==INT_MAX) ans[i] = -1;
        return ans;
    }
};