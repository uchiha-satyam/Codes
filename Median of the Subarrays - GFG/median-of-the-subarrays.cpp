//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
   public:
     long long help(int n, vector<int> arr, int m){
        unordered_map<int,int> mm;
        mm[0]++;
        int sum=0;
        long long ans=0, currElement=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<m){
                sum--;
                currElement-=mm[sum];
             }
             else{
                currElement+=mm[sum];
                sum++;
             }
            ans+=currElement;
            mm[sum]++;
        }
        return ans;
     }
     
     long long countSubarray(int N, vector<int> A, int M) {
         long long a = help(N,A,M);
         long long b = help(N,A,M+1);
         return a-b;
     }
 };

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends