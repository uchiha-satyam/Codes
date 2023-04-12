//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_set<char> oc, unoc;
        for(auto& ch : s)
        {
            if(oc.count(ch))
            {
                oc.erase(ch);
            }
            else
            {
                if(oc.size()<n&&unoc.count(ch)==0)
                oc.insert(ch);
                else
                unoc.insert(ch);
            }
        }
        return unoc.size();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends