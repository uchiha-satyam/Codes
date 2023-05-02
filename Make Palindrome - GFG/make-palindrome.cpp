//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    bool pal(string& s)
    {
        string ss = s;
        reverse(ss.begin(),ss.end());
        return s==ss;
    }
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_set<string> ss;
        for(int i=0; i<n; i++)
        {
            string s = arr[i];
            reverse(s.begin(),s.end());
            if(ss.count(s)) ss.erase(s);
            else ss.insert(arr[i]);
        }
        if(n%2)
        {
            if(ss.size()>1) return false;
            string s = *(ss.begin());
            return pal(s);
        }
        else
        {
            if(ss.size()) return false;
            return true;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends