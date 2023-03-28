//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    long long help(long long arr[], long long l, long long r)
    {
        if(l==r) return 0;
        long long mid = l + (r-l)/2;
        long long c1 = help(arr,l,mid);
        long long c2 = help(arr,mid+1,r);
        // cout<<l<<" "<<mid<<" "<<c1<<endl;
        // cout<<mid+1<<" "<<r<<" "<<c2<<endl;
        long long n1 = mid-l+1, n2 = r-mid;
        long long p1=l, p2=mid+1;
        vector<long long> a(n1), b(n2);
        for(long long i=0; i<n1; i++,p1++)
        a[i] = arr[p1];
        for(long long i=0; i<n2; i++,p2++)
        b[i] = arr[p2];
        p1 = p2 = 0;
        long long count = 0;
        long long p = l;
        while(p<=r)
        {
            if(p1<n1&&p2<n2)
            {
                if(a[p1]<=b[p2])
                {
                    arr[p] = a[p1];
                    p1++;
                }
                else
                {
                    count += n1-p1;
                    arr[p] = b[p2];
                    p2++;
                }
            }
            else if(p1<n1)
            {
                arr[p] = a[p1];
                p1++;
            }
            else
            {
                arr[p] = b[p2];
                p2++;
            }
            p++;
        }
        return count+c1+c2;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long ans = help(arr,0,n-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends