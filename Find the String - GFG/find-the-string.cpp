//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    void traverse(int& n, int& k, string str, unordered_map<string,vector<char>>& adj)
    {
        if(str.size() == n)
        {
            for(int i=0; i<k; i++)
            {
                adj[str].push_back('0'+i);
            }
            return;
        }
        for(int i=0; i<k; i++) traverse(n,k,str+(char)('0'+i),adj);
    }
    bool make(string& ans, unordered_map<string,vector<char>>& adj, unordered_map<string,unordered_set<char>>& visited, string str, int c, int s)
    {
        if(c==s) return true;
        c++;
        for(auto& x : adj[str])
        {
            if(visited[str].count(x)) continue;
            visited[str].insert(x);
            ans.push_back(x);
            if(make(ans,adj,visited,'?'+(str+x).substr(2),c,s)) return true;
            ans.pop_back();
            visited[str].erase(x);
        }
        return false;
    }
public:
    string findString(int n, int k) {
        // code here
        unordered_map<string,vector<char>> adj;
        unordered_map<string,unordered_set<char>> visited;
        traverse(n,k,"?",adj);
        string ans(n,'0');
        ans[0] = '?';
        if(make(ans,adj,visited,ans,0,(int)pow(k,n))) return ans.substr(1);
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends