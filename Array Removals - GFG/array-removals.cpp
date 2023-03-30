//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> l(n,0), r(n,0);
        for(int i=1; i<n; i++)
        {
            l[i] = l[i-1] + arr[i] - arr[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            r[n-i-1] = r[n-i-2] + arr[i+1] - arr[i];
        }
        int x=0, y=0, ans=INT_MAX;
        int diff = arr[n-1]-arr[0], fix = arr[n-1]-arr[0];
        while(diff>k&&x<n)
        {
            x++;
            diff = fix - l[x];
        }
        ans = x;
        while(true)
        {
            // cout<<x<<" "<<y<<" -> "<<diff<<endl;
            if(diff>k)
            {
                if(y<n) y++;
                else break;
            }
            else
            {
                ans = min(ans,x+y);
                if(x>0) x--;
                else break;
            }
            diff = fix - l[x] - r[y];
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends