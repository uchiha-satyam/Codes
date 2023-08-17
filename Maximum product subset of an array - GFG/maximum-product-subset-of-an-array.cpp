//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>& a, int n){
        //Write your code here
        int neg = 0, pos = 0, negMax = INT_MIN, zero = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]==0) zero++;
            else if(a[i]<0)
            {
                neg++;
                negMax = max(negMax,a[i]);
            }
            else pos++;
        }
        if(zero==n) return 0;
        if(pos==0&&neg==1)
        {
            if(zero) return 0;
            return negMax;
        }
        long long prod = 1, mod = 1e9+7;
        for(int i=0; i<n; i++)
        {
            if(a[i]==0) continue;
            else if(neg%2&&a[i]==negMax)
            {
                negMax = INT_MIN;
                continue;
            }
            prod *= a[i];
            prod %= mod;
        }
        return prod;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends