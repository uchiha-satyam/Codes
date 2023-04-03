//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        string s1="", s2="";
        for(int i=0; i<32; i++)
        {
            if(x!=0) s1 = (char)((x%2)+'0') + s1;
            else s1 = '0' + s1;
            if(y!=0) s2 = (char)((y%2)+'0') + s2;
            else s2 = '0' + s2;
            x=x>>1;
            y=y>>1;
        }
        // cout<<s1<<" "<<s2<<endl;
        for(int i=32-l; i>=32-r; i--)
        {
            s1[i] = (char)((s1[i]=='1'||s2[i]=='1') + '0');
        }
        return stoi(s1,nullptr,2);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends