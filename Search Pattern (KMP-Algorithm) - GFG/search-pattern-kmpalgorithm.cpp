//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
        void makePi(vector<int>& pi, string& pat)
        {
            int n = pat.size();
            for(int i=1; i<n; i++)
            {
                int j = pi[i-1];
                while(j!=pi[j]&&pat[i]!=pat[j])
                j = pi[j];
                if(pat[i]==pat[j])
                pi[i] = j+1;
            }
        }
        void kmp(vector<int>& pi, string& pat, string& txt, vector<int>& ans)
        {
            int n = txt.size(), m = pat.size();
            int i = 0, j = 0;
            while(i<n)
            {
                if(txt[i]==pat[j])
                {
                    i++;
                    j++;
                    if(j==m)
                    {
                        ans.push_back(i-m+1);
                        j--;
                        j = pi[j];
                    }
                }
                else
                {
                    if(j!=pi[j]) j = pi[j];
                    else i++,j=0;
                }
            }
        }
    public:
        vector<int> search(string pat, string txt)
        {
            //code here.
            int n = txt.size(), m = pat.size();
            vector<int> pi(m,0);
            makePi(pi,pat);
            // return pi;
            vector<int> ans;
            kmp(pi,pat,txt,ans);
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