//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> search(string pat, string txt)
        {
            //code here.
            vector<int> ans;
            int l1 = txt.length(), l2 = pat.length();
            vector<int> lps(l2+1,0);
            for(int i=1; i<=l2; i++)
            {
                if(pat[i-1]==pat[lps[i-1]]&&i-1!=lps[i-1])
                {
                    lps[i] = lps[i-1]+1;
                }
            }
            // for(int i=0; i<=l2; i++)
            // {
            //     cout<<lps[i]<<" ";
            // }
            // cout<<endl;
            int i=0, j=0;
            while(i<l1)
            {
                if(txt[i]==pat[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        i++;
                    }
                    else
                    {
                        j = lps[j];
                    }
                }
                // cout<<i<<"->"<<j<<" ";
                if(j==l2)
                {
                    // cout<<i<<" ";
                    ans.push_back(i-l2+1);
                    j = lps[j];
                }
            }
            // cout<<endl;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends