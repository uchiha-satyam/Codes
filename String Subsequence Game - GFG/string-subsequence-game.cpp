//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void get(set<string>& s, int i, int n, string str,string& org)
    {
        if(i==n)
        {
            if(str.back()!='a'&&str.back()!='e'&&str.back()!='i'&&str.back()!='o'&&str.back()!='u')
            s.insert(str);
            return;
        }
        get(s,i+1,n,str,org);
        get(s,i+1,n,str+org[i],org);
    }
  public:
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string> s;
        string ans = "";
        for(int i=0; i<S.length(); i++)
        {
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
            {
                ans += S[i];
                get(s,i+1,S.length(),ans,S);
                ans = "";
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends