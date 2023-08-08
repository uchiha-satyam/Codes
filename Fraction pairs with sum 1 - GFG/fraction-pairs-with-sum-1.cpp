//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>,int> mp;
        for(int i=0; i<n; i++)
        {
            int g = __gcd(numerator[i],denominator[i]);
            mp[{numerator[i]/g,denominator[i]/g}]++;
        }
        int ans = 0;
        for(auto& x : mp)
        {
            pair<int,int> p = {x.first.second - x.first.first, x.first.second};
            if(mp.count(p))
            {
                if(p.first==1&&p.second==2)
                ans += x.second * (x.second-1);
                else
                ans += x.second * mp[p];
            }
        }
        ans /= 2;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends