//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        set<int> st;
        for(int i=0; i<n; i++) st.insert(arr[i]);
        int prev = *(st.begin()), curr = 1, ans = 1;
        for(auto& x : st)
        {
            if(x-1==prev) curr++;
            else curr = 1;
            prev = x;
            ans = max(ans,curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends