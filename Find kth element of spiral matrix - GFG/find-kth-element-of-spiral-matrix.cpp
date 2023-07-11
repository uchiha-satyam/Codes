//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int rs=0, cs=0, re=n-1, ce=m-1;
 		int c=0;
 		while(c<n*m)
 		{
 		    for(int i=cs; i<=ce; i++)
 		    {
 		        c++;
 		        if(c==k) return a[rs][i];
 		    }
 		    rs++;
 		    for(int i=rs; i<=re; i++)
 		    {
 		        c++;
 		        if(c==k) return a[i][ce];
 		    }
 		    ce--;
 		    for(int i=ce; i>=cs; i--)
 		    {
 		        c++;
 		        if(c==k) return a[re][i];
 		    }
 		    re--;
 		    for(int i=re; i>=rs; i--)
 		    {
 		        c++;
 		        if(c==k) return a[i][cs];
 		    }
 		    cs++;
 		}
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends