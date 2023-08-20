//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans;
        for(int i = N-1; i>=0; i--)
        {
            ans = 0;
            for(int j=0; j<N; j++)
            {
                if(i!=N-1)
                {
                    int mx = Matrix[i+1][j];
                    if(j-1>=0) mx = max(mx,Matrix[i+1][j-1]);
                    if(j+1<N) mx = max(mx,Matrix[i+1][j+1]);
                    Matrix[i][j] += mx;
                }
                ans = max(ans,Matrix[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends