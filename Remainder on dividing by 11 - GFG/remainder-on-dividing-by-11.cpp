//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
        // code here
        int x1=0, x2=0;
        for(int i=0; i<x.length(); i++)
        {
            if(i%2) x1 += x[i]-'0';
            else x2 += x[i]-'0';
        }
        // if(x.length()%2) swap(x1,x2);
        return ((x1-x2)%11+11)%11;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends