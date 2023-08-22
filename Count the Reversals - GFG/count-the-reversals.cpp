//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int ans = 0, count = 0;
    for(auto& ch : s)
    {
        if(ch=='{') count++;
        else
        {
            if(count==0)
            {
                ans++;
                count++;
            }
            else count--;
        }
    }
    if(count%2) return -1;
    return ans += count/2;
}