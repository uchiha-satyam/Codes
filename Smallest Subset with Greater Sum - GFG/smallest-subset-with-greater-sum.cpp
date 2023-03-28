//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        long long sum=0;
        for(int i=0; i<N; i++)
        sum += Arr[i];
        long long sum2 = 0;
        sort(Arr.begin(),Arr.end(),greater<int>());
        for(int i=0; i<N; i++)
        {
            sum -= Arr[i];
            sum2 += Arr[i];
            if(sum2>sum) return i+1;
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends