//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxSum(int N){
        // code here
        if(N%2)
        {
            N++;
            N /= 2;
            return (N*(N-2) + (N-1)*(N+1));
        }
        else
        {
            N /= 2;
            return (N*N + (N+1)*(N-1));
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.maxSum(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends