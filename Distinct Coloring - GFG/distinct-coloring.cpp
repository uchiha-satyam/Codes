//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        long long int rf[N];
        copy(r, r+N, rf);
        long long int gf[N];
        copy(g, g+N, gf);
        long long int bf[N];
        copy(b, b+N, bf);
        for(int i=1; i<N; i++)
        {
            rf[i] += min(gf[i-1],bf[i-1]);
            gf[i] += min(rf[i-1],bf[i-1]);
            bf[i] += min(rf[i-1],gf[i-1]);
        }
        return min(rf[N-1],min(gf[N-1],bf[N-1]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends