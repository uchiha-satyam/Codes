//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
        void traverse(vector<vector<int>>& adj, vector<int>& group, int& grp, int n, long long& c)
        {
            group[n] = grp;
            c++;
            for(auto& x : adj[n])
            {
                if(group[x]!=-1) continue;
                traverse(adj,group,grp,x,c);
            }
        }
    public:
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            // code here
            vector<int> group(n,-1);
            vector<vector<int>> adj(n);
            for(int i=0; i<p; i++)
            {
                adj[pairs[i][0]].push_back(pairs[i][1]);
                adj[pairs[i][1]].push_back(pairs[i][0]);
            }
            long long ans = ((long long)n * (long long)(n-1))/2;
            for(int i=0; i<n; i++)
            {
                if(group[i]!=-1) continue;
                long long c = 0;
                traverse(adj,group,i,i,c);
                ans -= (c*(c-1))/2;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        vector<vector<int>> pairs(p,vector<int>(2));
        for(auto &i:pairs)
            for(auto &j:i)
                cin>>j;
        Solution a;
        cout<<a.numberOfPairs(pairs,p,n)<<endl;
    }
}
// } Driver Code Ends