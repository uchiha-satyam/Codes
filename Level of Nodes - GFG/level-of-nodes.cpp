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
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(0);
        q.push(-1);
        int level = 0;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            if(n==-1)
            {
                if(q.empty()) break;
                level++;
                q.push(-1);
                continue;
            }
            if(visited[n]) continue;
            visited[n] = true;
            if(n==X) return level;
            for(auto& e : adj[n])
            q.push(e);
        }
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