//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    string s1(n,'0'), s2(n,'1');
    int c1=0, c2=0;
    for(int i=0; i<n; i++)
    {
        if(i%2)
        {
            s1[i] = '1';
            s2[i] = '0';
        }
    }
    for(int i=0; i<n; i++)
    {
        if(S[i]!=s1[i]) c1++;
        if(S[i]!=s2[i]) c2++;
    }
    return min(c1,c2);
}