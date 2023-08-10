//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int> snake, ladder;
        for(int i=0; i<N; i++)
        {
            if(arr[2*i+1]>arr[2*i])
                ladder[arr[2*i]] = arr[2*i+1];
            else
                snake[arr[2*i]] = arr[2*i+1];
        }
        vector<int> dp(31,INT_MAX-1);
        dp[30] = 0;
        for(int i=29; i>0; i--)
        {
            if(ladder.count(i))
            {
                dp[i] = dp[ladder[i]];
                continue;
            }
            if(snake.count(i)) continue;
            for(int j=1; j<=6; j++)
            {
                if(i+j>30) break;
                dp[i] = min(dp[i],dp[i+j]+1);
            }
        }
        for(int i=1; i<30; i++)
        {
            if(snake.count(i))
            dp[i] = dp[snake[i]];
        }
        return dp[1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends