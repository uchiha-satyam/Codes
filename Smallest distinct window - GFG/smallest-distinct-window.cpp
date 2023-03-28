//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int n = str.length();
        unordered_map<char,int> m;
        int c = 0;
        for(int i=0; i<n; i++)
        {
            m[str[i]] = 1;
        }
        c = m.size();
        int s = 0, e = -1;
        while(c!=0)
        {
            e++;
            m[str[e]]--;
            if(m[str[e]]==0) c--;
        }
        int ans = e-s+1;
        while(e<n)
        {
            if(c==0)
            {
                ans = min(ans,e-s+1);
                m[str[s]]++;
                if(m[str[s]]==1) c++;
                s++;
            }
            else
            {
                e++;
                m[str[e]]--;
                if(m[str[e]]==0) c--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends