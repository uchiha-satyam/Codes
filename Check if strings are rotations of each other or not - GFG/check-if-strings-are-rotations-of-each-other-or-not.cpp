//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n = s2.size();
        if(s1.size()!=n) return false;
        int p1=0, p2=0;
        bool f = true, f2 = true;
        while(p2<n)
        {
            if(p1==n)
            {
                if(f2)
                {
                    p1 = 0;
                    f2 = false;
                }
                else return false;
            }
            if(s1[p1]==s2[p2])
            {
                p2++;
                f = true;
            }
            else
            {
                f = false;
                if(p2!=0)
                {
                    p2 = 0;
                    p1--;
                }
            }
            p1++;
        }
        return f;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends