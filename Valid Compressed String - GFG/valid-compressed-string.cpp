//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int getNum(string s)
    {
        if(s[0]-'0'>9||s[0]-'0'<0) return -1;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            int d = s[i]-'0';
            if(d<=9&&d>=0)
            {
                ans *= 10;
                ans += d;
            }
            else
            break;
        }
        return ans;
    }
  public:
    int checkCompressed(string S, string T) {
        // code here
        int p1 = 0, p2 = 0;
        int flag = 1;
        while(p2<T.length())
        {
            int num = getNum(T.substr(p2));
            // cout<<p1<<" "<<p2<<" "<<num<<endl;
            // cout<<num<<endl;
            if(num==-1)
            {
                if(S[p1]!=T[p2])
                {
                    flag = 0;
                    break;
                }
            }
            else
            // if(num!=-1)
            {
                p1 += num - 1;
                if(num!=0)
                p2 += floor(log10(num)+1) - 1;
                // if((p1>=S.length()-1)&&(p2>=T.length()-1))
                // {
                //     flag = 0;
                //     break;
                // }
            }
            p1++;
            p2++;
        }
        if(p1==S.length()&&p2==T.length()) return 1;
        else return 0;
        // return flag;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends