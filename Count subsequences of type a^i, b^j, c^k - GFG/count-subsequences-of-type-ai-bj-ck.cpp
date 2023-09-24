//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int mod = 1e9 + 7;
        int n = s.length();
        int a = 0, b = 0, c = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='a') a = (2*a + 1)%mod;
            else if(s[i]=='b') b = (a + (2*b)%mod)%mod;
            else c = (b + (2*c)%mod)%mod;
        }
        return c;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends