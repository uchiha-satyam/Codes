//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    int check(string s)
    {
        int x = 0;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            x = x*10 + (s[i]-'0');
        }
        if(x>=0&&x<256)
        {
            if((x!=0&&s[0]=='0')||(x==0&&n>1)) return -1;
            return x;
        }
        return -1;
    }
  public:
    vector<string> genIp(string &s) {
        // Your code here
        int n = s.length();
        int k = n-1;
        vector<string> ans;
        for(int p1=1; p1<=k; p1++)
        {
            int v1 = check(s.substr(0,p1));
            if(v1==-1)
            {
                // cout<<endl;
                break;
            }
            for(int p2=p1+1; p2<=k; p2++)
            {
                int v2 = check(s.substr(p1,p2-p1));
                if(v2==-1)
                {
                    // cout<<endl;
                    break;
                }
                for(int p3=p2+1; p3<=k; p3++)
                {
                    int v3 = check(s.substr(p2,p3-p2));
                    if(v3==-1)
                    {
                        // cout<<endl;
                        break;
                    }
                    int v4 = check(s.substr(p3));
                    if(v4==-1)
                    {
                        // cout<<endl;
                        continue;
                    }
                    string t = s.substr(0,p1)+'.'+s.substr(p1,p2-p1)+'.'+s.substr(p2,p3-p2)+'.'+s.substr(p3);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends