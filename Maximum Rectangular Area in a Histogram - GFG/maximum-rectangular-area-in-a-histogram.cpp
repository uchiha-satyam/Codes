//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<pair<long long,int>> st;
        vector<long long> left(n), right(n);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty()&&st.top().first>=arr[i]) st.pop();
            if(st.empty())
            right[i] = arr[i] * (n-i);
            else
            right[i] = arr[i] * (st.top().second - i);
            st.push({arr[i],i});
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++)
        {
            while(!st.empty()&&st.top().first>=arr[i]) st.pop();
            if(st.empty())
            left[i] = arr[i] * (i+1);
            else
            left[i] = arr[i] * (i - st.top().second);
            st.push({arr[i],i});
        }
        long long ans = 0;
        for(int i=0; i<n; i++)
        ans = max(ans,left[i] + right[i] - arr[i]);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends