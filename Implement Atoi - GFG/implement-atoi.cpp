//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        if(str.empty()) return 0;
        int f = (str[0]=='-')?-1:1;
        if(str[0]!='-'&&(str[0]-'0'>9||str[0]-'0'<0)) return -1;
        int next = atoi(str.substr(1));
        if(next < 0) return -1;
        if(f!=-1) next += (str[0]-'0')*pow(10,str.length()-1);
        next *= f;
        return next;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends