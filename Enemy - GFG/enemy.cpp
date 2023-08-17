//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //code here
            vector<bool> vec(n,false);
            for(int i=0; i<k; i++)
            vec[enemy[i][0]-1] = true;
            int mv = 0, v = 0, ans = 1;
            for(int i=0; i<n; i++)
            {
                if(!vec[i]) v++;
                else v = 0;
                mv = max(mv,v);
            }
            ans *= mv;
            vec.clear();
            vec.resize(m,false);
            for(int i=0; i<k; i++)
            vec[enemy[i][1]-1] = true;
            mv = 0, v = 0;
            for(int i=0; i<m; i++)
            {
                if(!vec[i]) v++;
                else v = 0;
                mv = max(mv,v);
            }
            ans *= mv;
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
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends