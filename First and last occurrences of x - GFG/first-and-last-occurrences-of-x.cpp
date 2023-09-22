//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int a[], int n , int x )
    {
        // code here
        int s=0,e=n-1,pos1=-1,pos2=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(a[mid]==x){
                 pos1=mid;
                e=mid-1;
            }
            else if(a[mid]>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        s=0,e=n-1;
         while(s<=e){
            int mid=(s+e)/2;
            if(a[mid]==x){
                pos2=mid;
                s=mid+1;
            }
            else if(a[mid]>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        vector<int> ans;
        ans.push_back(pos1);
        ans.push_back(pos2);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends