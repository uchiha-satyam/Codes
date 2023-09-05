//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    void dfs(int c, vector<int> adj[], vector<int> nadj[], stack<int>& st, vector<bool>& vis, vector<int>& vec)
    {
        vis[c] = true;
        vec.push_back(c);
        for(auto x : adj[c])
        {
            nadj[x].push_back(c);
            if(vis[x]) continue;
            dfs(x,adj,nadj,st,vis,vec);
        }
        st.push(c);
    }
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> nadj[V];
        stack<int> st, nst;
        vector<bool> vis(V,false);
        vector<int> vec;
        for(int i=0; i<V; i++)
        {
            if(vis[i]) continue;
            vec.clear();
            dfs(i,adj,nadj,st,vis,vec);
        }
        vector<vector<int>> ans;
        for(int i=0; i<V; i++)
        vis[i] = false;
        while(!st.empty())
        {
            int n = st.top();
            st.pop();
            if(vis[n]) continue;
            vec.clear();
            dfs(n,nadj,adj,nst,vis,vec);
            sort(vec.begin(),vec.end());
            ans.push_back(vec);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends