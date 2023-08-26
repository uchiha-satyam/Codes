//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    bool isValid(vector<vector<int>>& adj, int m, int n, int s)
    {
        vector<int> vec(m);
        iota(vec.begin(),vec.end(),1);
        vector<set<int>> available(n,set<int>(vec.begin(),vec.end()));
        vector<bool> visited(n,false);
        vector<int> colors(n,-1);
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            if(colors[(s+i)%n]!=-1) continue;
            queue<int> q;
            q.push((s+i)%n);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                visited[node] = true;
                if(available[node].empty())
                {
                    // cout<<node<<"->error"<<endl;
                    flag = false;
                    break;
                }
                int color = *(available[node].begin());
                colors[node] = color;
                for(auto& vtx : adj[node])
                {
                    if(visited[vtx]) continue;
                    available[vtx].erase(color);
                    q.push(vtx);
                }
            }
        }
        // for(int i=0; i<n; i++) cout<<colors[i]<<" ";
        // cout<<endl;
        return flag;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(graph[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            bool flag = isValid(adj,m,n,i);
            // cout<<i<<" "<<flag<<endl;
            if(flag) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends