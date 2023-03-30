//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<int> mi(n), ma(n);
    int l1=INT_MAX, l2=0, l3=0;
    for(int i=0; i<n; i++)
    {
        l1 = min(l1,price[i]);
        l2 = price[i] - l1;
        l3 = max(l3,l2);
        mi[i] = l3;
    }
    l1 = INT_MIN;
    l3 = 0;
    for(int i=n-1; i>=0; i--)
    {
        l1 = max(l1,price[i]);
        l2 = l1 - price[i];
        l3 = max(l3,l2);
        ma[i] = l3;
    }
    int ans = 0, realAns = 0;
    for(int i=0; i<n; i++)
    {
        ans = 0;
        if(i>0) ans += mi[i-1];
        ans += ma[i];
        realAns = max(realAns,ans);
    }
    return realAns;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends