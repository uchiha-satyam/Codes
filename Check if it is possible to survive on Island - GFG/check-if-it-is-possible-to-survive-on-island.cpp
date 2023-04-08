//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int s, int n, int m){
        // code here
        if(m>n) return -1;
        int reqPerWeek = 7*m;
        int daysPerWeek = ceil((1.0*reqPerWeek)/n);
        if(daysPerWeek>6&&s>6) return -1;
        int remPerWeek = n*daysPerWeek - reqPerWeek;
        int completeWeeks = s/7;
        int remDays = s%7;
        int reqAfterCompleteWeeks = m*remDays - remPerWeek*completeWeeks;
        int extraDays = 0;
        if(reqAfterCompleteWeeks>0) extraDays = ceil((1.0*reqAfterCompleteWeeks)/n);
        else extraDays = reqAfterCompleteWeeks/n;
        int totalDays = daysPerWeek*completeWeeks + extraDays;
        return totalDays;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends