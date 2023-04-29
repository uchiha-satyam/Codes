//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        vector<int> v1(n), v2(n);
        for(int i=0; i<n; i++)
        {
            v1[i] = intervals[i][0];
            v2[i] = intervals[i][1];
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int ans = -1;
        int p1=0, p2=0;
        int c = 0;
        while(p2<n)
        {
            if(p1<n&&v1[p1]<=v2[p2])
            {
                p1++;
                c++;
            }
            else
            {
                p2++;
                c--;
            }
            if(c>=k)
            {
                ans = v2[p2];
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
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends