//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int p1 = 0, p2 = m-1;
        sort(arr,arr+n);
        sort(brr,brr+m);
        int mindiff = INT_MAX, ap1 = -1, ap2 = -1;
        while(p1<n&&p2>=0)
        {
            // cout<<arr[p1]<<" "<<brr[p2]<<endl;
            int diff = abs(x - (arr[p1]+brr[p2]));
            if(diff<mindiff)
            {
                mindiff = diff;
                ap1 = p1;
                ap2 = p2;
            }
            if(x>arr[p1]+brr[p2])
            p1++;
            else
            p2--;
        }
        // cout<<mindiff<<endl;
        return {arr[ap1],brr[ap2]};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends