//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long ans = 0;
	   // for(int i=0; i<n; i++)
	   // cout<<arr[i]<<" ";
	   // cout<<endl;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i]>=sum/3) continue;
	        for(int j=i+1; j<n; j++)
	        {
	            long long k = sum-arr[i]-arr[j];
	            if(k<=arr[j]) continue;
	            int s = 0, e = n-1, mid = s + (e-s)/2;
	            while(s<=e)
	            {
	                mid = s + (e-s)/2;
	                if(arr[mid]==k) break;
	                else if(arr[mid]>k) e = mid-1;
	                else s = mid+1;
	            }
	            if(arr[mid]>=k)
	            {
	               // cout<<arr[i]<<" "<<arr[j]<<" "<<k<<" ? "<<arr[mid]<<"->"<<arr[mid-1]<<" "<<mid-1-j<<endl;
	                mid--;
	            }
	            ans += max(0,mid-j);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends