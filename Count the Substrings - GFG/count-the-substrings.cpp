//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        vector<int> lc(S.length()+1,0), uc(S.length()+1,0);
        int l=0, u=0;
        for(int i=0; i<S.length(); i++)
        {
            char ch = S[i];
            if(ch-'a'>=0&&ch-'a'<26) l++;
            else u++;
            lc[i] = l;
            uc[i] = u;
            // cout<<lc[i]<<" "<<uc[i]<<endl;
        }
        int ans = 0;
        for(int i=0; i<S.length(); i++)
        {
            for(int j=i+1; j<S.length(); j++)
            {
                if((lc[j]-lc[i-1])==(uc[j]-uc[i-1])) ans++;
            }
        }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends