//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    vector<int> lc(n), rc(n);
	    int c = 0;
	    long long ans = INT_MIN, p=1;
	    for(int i=0; i<n; i++)
	    {
	        ans = max(ans,(long long)arr[i]);
	        if(arr[i]==0) c = 0;
	        else if(arr[i]<0)
	        {
	            c++;
	            rc[i] = c;
	        }
	    }
	    c = 0;
	    for(int i=n-1; i>=0; i--)
	    {
	        if(arr[i]==0) c = 0;
	        else if(arr[i]<0)
	        {
	            c++;
	            lc[i] = c;
	        }
	    }
	    int f = 0;
	    bool flag = false;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i]==0||(arr[i]<0&&(f+lc[i])%2)&&lc[i]==1)
	        {
	            if(flag) ans = max(ans,p);
	            p = 1;
	            f = 0;
	            flag = false;
	        }
	        else
	        {
	            flag = true;
	            p *= arr[i];
	            if(arr[i]<0) f++;
	        }
	       // cout<<p<<" ";
	    }
	   // cout<<endl;
	    if(flag) ans = max(ans,p);
	    p = 1;
	    flag = false;
	    for(int i=n-1; i>=0; i--)
	    {
	        if(arr[i]==0||(arr[i]<0&&(f+rc[i])%2)&&rc[i]==1)
	        {
	            if(flag) ans = max(ans,p);
	            p = 1;
	            f = 0;
	            flag = false;
	        }
	        else
	        {
	            flag = true;
	            p *= arr[i];
	            if(arr[i]<0) f++;
	        }
	    }
	    if(flag) ans = max(ans,p);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends