//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void traverse(map<int,vector<pair<int,int>>>& adj, int node, int& val, vector<vector<int>>& ans, vector<bool>& visited)
    {
        visited[node] = true;
        bool flag = true;
        for(auto& x : adj[node])
        {
            if(visited[x.first]) continue;
            flag = false;
            val = min(val,x.second);
            traverse(adj,x.first,val,ans,visited);
        }
        if(flag) ans.back().push_back(node);
    }
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<bool> visited(n,false);
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> adj;
        unordered_map<int,int> indeg;
        queue<int> q;
        for(int i=0; i<p; i++)
        {
            adj[a[i]].push_back({b[i],d[i]});
            indeg[b[i]]++;
            // adj[b[i]].push_back({a[i],d[i]});
        }
        for(auto& x : adj)
        if(x.second.size()==1&&indeg[x.first]==0) q.push(x.first);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(visited[node]) continue;
            ans.push_back({node});
            int val = INT_MAX;
            traverse(adj,node,val,ans,visited);
            ans.back().push_back(val);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends