//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int pos=0, neg=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='L')
            {
                pos++;
                pos += neg;
                neg = 0;
            }
            if(s[i]=='R'&&pos!=0)
            {
                neg--;
            }
            if(pos>=m) return 0;
        }
        pos = 0;
        neg = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='R')
            {
                pos++;
                pos += neg;
                neg = 0;
            }
            if(s[i]=='L'&&pos!=0)
            {
                neg--;
            }
            if(pos>=m) return 0;
        }
        pos = 0;
        neg = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='U')
            {
                pos++;
                pos += neg;
                neg = 0;
            }
            if(s[i]=='D'&&pos!=0)
            {
                neg--;
            }
            if(pos>=n) return 0;
        }
        pos = 0;
        neg = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='D')
            {
                pos++;
                pos += neg;
                neg = 0;
            }
            if(s[i]=='U'&&pos!=0)
            {
                neg--;
            }
            if(pos>=n) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends