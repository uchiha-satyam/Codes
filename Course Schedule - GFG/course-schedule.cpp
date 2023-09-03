//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& cvis, int i, stack<int>& st)
    {
        // cout<<i<<" ";
        vis[i] = true;
        cvis[i] = true;
        for(auto& x : adj[i])
        {
            if(cvis[x])
            {
                // cout<<"cycle"<<endl;
                st.push(-1);
                return;
            }
            if(vis[x]) continue;
            dfs(adj,vis,cvis,x,st);
        }
        cvis[i] = false;
        st.push(i);
    }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int> st;
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++)
        {
            if(vis[i]) continue;
            vector<bool> cvis(n,false);
            dfs(adj,vis,cvis,i,st);
            // cout<<endl;
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            if(st.top()==-1)
            {
                // cout<<"-1"<<endl;
                ans.clear();
                return ans;
            }
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends