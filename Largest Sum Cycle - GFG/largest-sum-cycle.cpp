//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    long long nc = 0;
    vector<bool> visited(N,false);
    int mSum = -1;
    for(int i=0; i<N; i++)
    {
        if(visited[i]) continue;
        int sum = i;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        int p = i;
        while(Edge[p]!=-1&&!visited[Edge[p]])
        {
            p = Edge[p];
            q.push(p);
            sum += p;
            visited[p] = true;
        }
        if(Edge[p]==-1) continue;
        int c = Edge[p];
        while(q.front()!=c)
        {
            sum -= q.front();
            q.pop();
            if(q.empty())
            {
                sum = -1;
                break;
            }
        }
        mSum = max(sum,mSum);
    }
    return mSum;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends