//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    long long ans = 0;
    int s = 0, e = n;
    bool flag = true;
    while(true)
    {
        e--;
        ans += abs(arr[s]-arr[e]);
        if(s==e) break;
        s++;
        ans += abs(arr[s]-arr[e]);
        if(s==e) break;
    }
    ans += abs(arr[s]-arr[0]);
    return ans;
}