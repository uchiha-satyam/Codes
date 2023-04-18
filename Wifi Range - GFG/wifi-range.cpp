//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int prev = 0;
        int i=0;
        while(S[i]!='1')
        {
            i++;
        }
        if(i>X) return false;
        prev = i;
        for(; i<N; i++)
        {
            // cout<<i<<" "<<prev<<endl;
            if(S[i]=='1')
            {
                if(i-prev-1>2*X) return false;
                prev = i;
            }
        }
        if(N-prev-1>X) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends