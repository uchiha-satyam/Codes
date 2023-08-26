//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        vector<int> ans;
        queue<int> q1, q2;
        int c = 1;
        while(c<=n)
        {
            if(c<=n/2) q1.push(q.front());
            else q2.push(q.front());
            q.pop();
            c++;
        }
        c = 0;
        while(c<n)
        {
            if(c%2==0)
            {
                ans.push_back(q1.front());
                q1.pop();
            }
            else
            {
                ans.push_back(q2.front());
                q2.pop();
            }
            c++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends