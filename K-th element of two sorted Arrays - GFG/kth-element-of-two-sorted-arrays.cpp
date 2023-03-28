//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int p1=0, p2=0, p=0;
        int ans = 0;
        while(p<k)
        {
            if(p1<n&&p2<m)
            {
                if(arr1[p1]<=arr2[p2])
                {
                    ans = arr1[p1];
                    p1++;
                }
                else
                {
                    ans = arr2[p2];
                    p2++;
                }
            }
            else if(p1<n)
            {
                ans = arr1[p1];
                p1++;
            }
            else
            {
                ans = arr2[p2];
                p2++;
            }
            p++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends