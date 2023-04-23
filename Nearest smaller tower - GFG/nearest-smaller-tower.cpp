//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans1(n,-1), ans2(n,-1), realAns(n,-1);
        for(int i=1; i<n; i++)
        {
            int p = i-1;
            while(p!=-1&&arr[i]<=arr[p])
            {
                p = ans1[p];
            }
            if(p!=-1) ans1[i] = p;
        }
        for(int i=n-2; i>=0; i--)
        {
            int p = i+1;
            while(p!=-1&&arr[i]<=arr[p])
            {
                p = ans2[p];
            }
            if(p!=-1) ans2[i] = p;
        }
        for(int i=0; i<n; i++)
        {
            int d1 = INT_MAX, d2 = INT_MAX;
            if(ans1[i]!=-1) d1 = abs(i-ans1[i]) - 1;
            if(ans2[i]!=-1) d2 = abs(i-ans2[i]) - 1;
            if(d1<d2) realAns[i] = ans1[i];
            else if(d1>d2) realAns[i] = ans2[i];
            else
            {
                if(d1==INT_MAX) realAns[i] = -1;
                else
                {
                    if(arr[ans1[i]]>arr[ans2[i]]) realAns[i] = ans2[i];
                    else realAns[i] = ans1[i];
                }
            }
        }
        return realAns;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends