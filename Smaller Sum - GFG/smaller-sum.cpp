//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        multiset<long long> ms;
        for(int i=0; i<n; i++)
        {
            ms.insert(arr[i]);
        }
        long long sum = 0;
        unordered_map<int,long long> m;
        for(auto& x : ms)
        {
            if(!m.count(x)) m[x] = sum;
            sum += x;
        }
        vector<long long> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = m[arr[i]];
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends