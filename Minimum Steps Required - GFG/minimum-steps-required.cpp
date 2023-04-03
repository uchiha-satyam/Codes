//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int c1=0, c2=0, n=str.length();
    char prev = str[0];
    if(str[0]=='a') c1++;
    else c2++;
    for(int i=0; i<n; i++)
    {
        if(str[i]!=prev)
        {
            if(str[i]=='a') c1++;
            else c2++;
        }
        prev = str[i];
    }
    return min(c1,c2)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends