//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here,
        map<int,int> m;
        for(int i=0; i<k; i++)
        m[arr[i]]++;
        vector<int> ans(n-k+1,m.rbegin()->first);
        for(int i=k; i<n; i++)
        {
            m[arr[i]]++;
            m[arr[i-k]]--;
            if(m[arr[i-k]]<=0) m.erase(arr[i-k]);
            ans[i-k+1] = m.rbegin()->first;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends