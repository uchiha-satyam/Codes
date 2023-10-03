//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        long long count=0;
        long long v1=26,sum=0;
        while(1){
            n-=v1;
            if(n<=0){
                n+=v1;
                ++count;
                break;
            }
            v1*=26;
            ++count;
        }
        string ans;
        for(int i=0;i<count;++i){
            ans.push_back('A');
        }
        int pos=0;
        long long val1=26;
        while(1){
            if(val1>=n){
                val1/=26;
                break;
            }
            val1*=26;
            ++pos;
        }
        //cout << pos << "\n";
        for(int i=pos;i>=0;--i){
            long long val=n/val1;
            if(n%val1==0)
            val--;
            if(val<0)
            val=25;
            ans[i]='A'+val;
            n=(n%val1);
            val1/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends