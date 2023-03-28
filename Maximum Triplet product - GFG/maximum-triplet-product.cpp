//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long ans = INT_MIN;
    	long long pm1=0, pm2=0, pm3=0, nm1=0, nm2=0, mm1=INT_MAX, mm2=INT_MAX, mm3=INT_MAX;
    	int z = 0;
    	for(int i=0; i<n; i++)
    	{
    	    if(arr[i]==0) z++;
    	    else if(arr[i]>0)
    	    {
    	        if(arr[i]>pm1)
    	        {
    	            pm3 = pm2;
    	            pm2 = pm1;
    	            pm1 = arr[i];
    	        }
    	        else if(arr[i]>pm2)
    	        {
    	            pm3 = pm2;
    	            pm2 = arr[i];
    	        }
    	        else if(arr[i]>pm3)
    	        {
    	            pm3 = arr[i];
    	        }
    	    }
    	    else
    	    {
    	        arr[i] = llabs(arr[i]);
    	        if(arr[i]>nm1)
    	        {
    	            nm2 = nm1;
    	            nm1 = arr[i];
    	        }
    	        else if(arr[i]>nm2)
    	        {
    	            nm2 = arr[i];
    	        }
    	        if(arr[i]<mm1)
    	        {
    	            mm3 = mm2;
    	            mm2 = mm1;
    	            mm1 = arr[i];
    	        }
    	        else if(arr[i]<mm2)
    	        {
    	            mm3 = mm2;
    	            mm2 = arr[i];
    	        }
    	        else if(arr[i]<mm3)
    	        {
    	            mm3 = arr[i];
    	        }
    	    }
    	}
    	if(z) ans = 0;
    // 	cout<<pm1<<" "<<pm2<<" "<<pm3<<" "<<nm1<<" "<<nm2<<" "<<mm1<<" "<<mm2<<" "<<mm3<<endl;
    	if(pm3!=0) ans = max(ans,pm1*pm2*pm3);
    	if(pm2!=0&&mm1!=INT_MAX) ans = max(ans,pm1*pm2*mm1*-1);
    	if(pm1!=0&&nm2!=0) ans = max(ans,pm1*nm1*nm2);
    	if(mm3!=INT_MAX) ans = max(ans,mm1*mm2*mm3*-1);
    // 	ans = max(ans,max(pm1*pm2*pm3,max(pm1*pm2*nm1*-1,max(pm1*nm1*nm2,nm1*nm2*nm3*-1))));
    	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends