//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool traverse(int root, vector<bool>& vis, int& n, int c, vector<vector<int>>& adj)
    {
        if(c==n) return true;
        vis[root] = true;
        for(auto& x : adj[root])
        {
            if(vis[x]) continue;
            if(traverse(x,vis,n,c+1,adj)) return true;
        }
        vis[root] = false;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> indeg(N,0);
        vector<vector<int>> adj(N);
        for(auto& x : Edges)
        {
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
            indeg[x[1]-1]++;
            indeg[x[0]-1]++;
        }
        vector<bool> vis(N,false);
        vector<int> str;
        int m = INT_MAX;
        for(int i=0; i<N; i++) m = min(m,indeg[i]);
        for(int i=0; i<N; i++)
        if(indeg[i]==m) str.push_back(i);
        for(auto& x : str)
        if(traverse(x,vis,N,1,adj)) return true;
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends