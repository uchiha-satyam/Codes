//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(S>9*D) return "-1";
        S -= 1;
        string s(D,'0');
        s[0] = '1';
        for(int i=D-1; i>=0; i--)
        {
            int v = min(S,9-(s[i]-'0'));
            s[i] += v;
            S -= v;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends