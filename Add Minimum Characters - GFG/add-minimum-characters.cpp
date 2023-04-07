//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n = str.length();
        int p1 = 0, p2 = n-1;
        int c = 0;
        while(p1<p2)
        {
            if(str[p1]==str[p2])
            {
                p1++;
                p2--;
            }
            else
            {
                c++;
                p1 = 0;
                p2 = n-1-c;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends