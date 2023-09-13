//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S==0)
        {
            if(N==1) return "0";
            return "-1";
        }
        string s(N,'0');
        int i = 0;
        while(S>0&&i<N)
        {
            int x = min(9,S);
            S -= x;
            s[i] = ('0' + x);
            i++;
        }
        if(S>0) return "-1";
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends