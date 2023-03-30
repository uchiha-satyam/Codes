//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int n,vector<int> &a,vector<int> &b){
        stack<int> s;
        unordered_set<int> o;
        int p1=0, p2=0;
        while(p2<n)
        {
            // cout<<p1<<" "<<p2<<endl;
            if(p1<n&&a[p1]==b[p2])
            {
                p1++;
                p2++;
                continue;
            }
            if(o.count(b[p2]))
            {
                if(s.top()==b[p2])
                {
                    s.pop();
                    // o.erase(b[p2]);
                    p2++;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(p1>=n) return 0;
                s.push(a[p1]);
                o.insert(a[p1]);
                p1++;
            }
        }
        if(s.empty()) return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends