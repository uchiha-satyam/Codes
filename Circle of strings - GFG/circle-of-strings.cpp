//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void dfs(char ch, unordered_map<char,bool>& visited, unordered_map<char,vector<char>>& adj)
    {
        visited[ch] = true;
        for(auto& x : adj[ch])
        {
            if(visited[x]) continue;
            dfs(x,visited,adj);
        }
    }
    public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        unordered_map<char,vector<char>> adj;
        unordered_map<char,bool> visited;
        unordered_map<char,int> in, out;
        for(auto& x : A)
        {
            adj[x[0]].push_back(x.back());
            out[x[0]]++;
            in[x.back()]++;
            visited[x[0]] = false;
        }
        dfs(A[0][0],visited,adj);
        for(auto& x : visited)
        {
            if(x.second==false||in[x.first]!=out[x.first]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends