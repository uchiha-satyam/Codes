//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int cuts(string s){
        //code
        // cout<<s<<endl;
        if(s.length()==0) return 0;
        if(s.find('0')==string::npos) return s.length();
        long long temp = stoll(s,0,2);
        if(temp==0||s[0]=='0') return -1;
        double d = log(temp) * 1.0 / log(5);
        int x = d;
        double diff = d - x;
        // cout<<" "<<d<<" "<<x<<" "<<diff<<" "<<(diff>0.0000001)<<endl;
        if(diff<=0.0000001) return 1;
        else
        {
            int a1=INT_MAX, a2=INT_MAX, a3=INT_MAX, a4=INT_MAX;
            if(s.substr(0,3)=="101")
            {
                a1 = 1 + cuts(s.substr(3));
            }
            else if(s.substr(0,1)=="1")
            {
                a3 = 1 + cuts(s.substr(1));
            }
            if(s.substr(s.length()-3)=="101")
            {
                a2 = 1 + cuts(s.substr(0,s.length()-3));
            }
            else if(s.substr(s.length()-1)=="1")
            {
                a4 = 1 + cuts(s.substr(0,s.length()-1));
            }
            int ans = min(a1,min(a2,min(a3,a4)));
            if(ans==0||ans==INT_MAX) return -1;
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends