//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> vis(V,false);
	    queue<int> q;
	    bool flag = false;
	    int c = 0;
	    q.push(0);
	    q.push(-1);
	    while(!q.empty())
	    {
	        int n = q.front();
	        q.pop();
	        if(n==-1)
	        {
	            if(q.empty()) break;
	            q.push(-1);
	            c++;
	            continue;
	        }
	        if(vis[n]) continue;
	        if(n==X)
	        {
	            flag = true;
	            break;
	        }
	        vis[n] = true;
	        for(auto& x : adj[n])
	        {
	            if(vis[x]) continue;
	            q.push(x);
	        }
	    }
	    if(flag) return c;
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends