//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int rem1 = N%(2*K);
        int x = (N-rem1)/2;
        if(rem1==0) return x+1;
        else if(rem1<=K)
        {
            return x+rem1;
        }
        else
        {
            rem1 %= K;
            return N-x-rem1+1;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends