//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        vector<int> vec;
        int ans = 0;
        vec.push_back(0);
        for(int i=0; i<n; i++)
        {
            if((a[i]==0&&vec.back()<0)||(a[i]==1&&vec.back()>0)) vec.push_back(0);
            if(a[i]==0) vec.back()++;
            else
            {
                ans++;
                vec.back()--;
            }
        }
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<vec.size(); i++)
        {
            sum += vec[i];
            if(sum<=0) sum = 0;
            maxSum = max(maxSum,sum);
        }
        return ans + maxSum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends