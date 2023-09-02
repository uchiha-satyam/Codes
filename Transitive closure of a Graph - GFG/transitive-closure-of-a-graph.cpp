//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
    void dfs(int n, int& N, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[n] = 1;
        for(int i=0; i<N; i++)
        {
            if(adj[n][i]==0||vis[i]) continue;
            dfs(i,N,adj,vis);
        }
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>> vis(N,vector<int>(N,0));
        for(int i=0; i<N; i++)
        {
            dfs(i,N,graph,vis[i]);
        }
        return vis;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends