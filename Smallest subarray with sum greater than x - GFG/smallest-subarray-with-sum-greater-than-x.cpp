//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int s = 0, e = -1;
        int sum = 0;
        while(sum<=x&&e<n)
        {
            e++;
            sum += arr[e];
        }
        while(sum>x&&s<n)
        {
            sum -= arr[s];
            s++;
        }
        s--;
        sum += arr[s];
        int ans = e-s+1;
        // cout<<s<<" "<<e<<endl;
        while(e<n-1)
        {
            e++;
            sum += arr[e];
            // cout<<sum<<endl;
            while(sum>x&&s<n)
            {
                sum -= arr[s];
                s++;
            }
            s--;
            sum += arr[s];
            // cout<<s<<" "<<e<<endl;
            ans = min(ans,e-s+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends