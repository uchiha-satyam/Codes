//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include<bits/stdc++.h>
class Solution {
    bool is(int a)
    {
        int b = 0, c = a;
        int p = pow(10,ceil(log10(a))-1);
        while(c>0)
        {
            b += (c%10) * p;
            p /= 10;
            c /= 10;
        }
        // cout<<a<<" "<<b<<endl;
        if(a==b) return true;
        return false;
    }
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	int c = 1;
    	for(int i=0; i<n; i++)
    	c = c&&is(a[i]);
    	return c;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends