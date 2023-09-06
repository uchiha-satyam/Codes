//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    void getList(vector<string>& wl)
    {
        vector<bool> prime(10000,false);
        for(int i=2; i<=sqrt(10000); i++)
        {
            if(prime[i]) continue;
            for(int j=i*i; j<10000; j+=i) prime[j] = true;
        }
        for(int i=1000; i<10000; i++)
        if(!prime[i]) wl.push_back(to_string(i));
    }
public:
    int solve(int Num1,int Num2)
    {   
        //code here
        vector<string> wl;
        string bw = to_string(Num1);
        string ew = to_string(Num2);
        getList(wl);
        unordered_map<string,int> mp;
        int n = wl.size();
        vector<vector<int>> adj(n);
        for(int s=0; s<n; s++)
        {
            auto& x = wl[s];
            for(int i=0; i<4; i++)
            {
                char ch = x[i];
                char rp = '0';
                if(i==0) rp = '1';
                for(; rp<='9'; rp++)
                {
                    x[i] = rp;
                    if(mp.count(x))
                    {
                        adj[s].push_back(mp[x]);
                        adj[mp[x]].push_back(s);
                    }
                }
                x[i] = ch;
            }
            mp[x] = s;
        }
        int src = mp[bw];
        int dst = mp[ew];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,false);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int val = dist[node];
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            for(auto& x : adj[node])
            {
                if(vis[x]||dist[x]<=val+1) continue;
                dist[x] = val+1;
                pq.push({dist[x],x});
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends