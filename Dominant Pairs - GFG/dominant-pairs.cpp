//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(),arr.begin()+n/2);
        sort(arr.begin()+n/2,arr.end());
        // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        int ans = 0;
        int p1 = 0, p2 = n/2;
        while(p1<n/2&&p2<n)
        {
            if(arr[p1]>=arr[p2]*5)
            {
                ans += n/2-p1;
                p2++;
            }
            else
            {
                p1++;
            }
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends