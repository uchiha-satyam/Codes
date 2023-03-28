//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        long long sum = 0, m = INT_MAX;
        vector<long long> neg;
        for(int i=0; i<n; i++)
        {
            if(a[i]<0)
            {
                neg.push_back(llabs(a[i]));
            }
            else
            {
                sum += a[i];
            }
            m = min(m,llabs(a[i]));
        }
        sort(neg.begin(),neg.end());
        for(int i=neg.size()-1; i>=0; i--)
        {
            if(k>0)
            {
                sum += neg[i];
                k--;
            }
            else
            {
                sum -= neg[i];
            }
        }
        k = k%2;
        if(k) sum -= 2*m;
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends