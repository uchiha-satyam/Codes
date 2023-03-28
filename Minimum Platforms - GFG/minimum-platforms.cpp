//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans = 0;
    	int c = 0;
    	int p1=0, p2=0;
    	while(p1<n||p2<n)
    	{
    	    if(p1<n&&p2<n)
    	    {
    	        if(arr[p1]<=dep[p2])
    	        {
    	            c++;
    	            p1++;
    	        }
    	        else
    	        {
    	            c--;
    	            p2++;
    	        }
    	    }
    	    else p2++;
    	    ans = max(ans,c);
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends