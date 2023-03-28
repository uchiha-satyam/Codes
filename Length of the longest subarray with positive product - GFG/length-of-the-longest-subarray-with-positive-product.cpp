//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           vector<int> v;
           int s=0, e=0;
           bool sf=false;
           int c1=0, c2=0;
           for(int i=0; i<n; i++)
           {
               if(arr[i]==0)
               {
                   if(c2%2==0)
                   v.push_back(c1);
                   else
                   v.push_back(max(c1-1-s,c1-1-e));
                   c1=0;
                   c2=0;
                   sf=false;
                   s=0;
                   e=0;
               }
               else
               {
                   c1++;
                   e++;
                   if(arr[i]<0)
                   {
                       c2++;
                       sf=true;
                       e=0;
                   }
                   if(sf==false) s++;
               }
           }
           if(c2%2==0)
           v.push_back(c1);
           else
           v.push_back(max(c1-1-s,c1-1-e));
           int ans = 0;
           for(int i=0; i<v.size(); i++)
           ans = max(ans,v[i]);
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends