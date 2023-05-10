//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> l(N), r(N);
        int x = INT_MIN;
        for(int i=0; i<N; i++)
        {
            x = max(x,A[i]);
            l[i] = x;
        }
        x = INT_MAX;
        for(int i=N-1; i>=0; i--)
        {
            r[i] = x;
            x = min(x,A[i]);
        }
        int count = 0;
        for(int i=0; i<N-1; i++)
        {
            if(l[i]+r[i]>=K) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends