//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class trie
{
    public:
    vector<trie*> child;
    bool isLeaf;
    trie()
    {
        child.resize(26,NULL);
        isLeaf = false;
    }
    void insert(string s)
    {
        if(s.empty())
        {
            this->isLeaf = true;
            return;
        }
        if(!this->child[s[0]-'a']) this->child[s[0]-'a'] = new trie();
        this->child[s[0]-'a']->insert(s.substr(1));
    }
    bool search(string s)
    {
        if(s.empty())
        return this->isLeaf;
        if(!this->child[s[0]-'a']) return false;
        return this->child[s[0]-'a']->search(s.substr(1));
    }
};

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        trie t;
        for(auto& x : dict) t.insert(x);
        n = s.size();
        vector<vector<vector<string>>> dp(n,vector<vector<string>>(n));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                for(int k=i; k<j; k++)
                {
                    // cout<<i<<" "<<k<<" "<<t.search(s.substr(i,k-i+1))<<endl;
                    string str = s.substr(i,k-i+1);
                    if(dp[k+1][j].size()&&t.search(str))
                    {
                        for(auto sentence : dp[k+1][j])
                        {
                            sentence  = str + " " + sentence;
                            dp[i][j].push_back(sentence);
                        }
                    }
                }
                if(t.search(s.substr(i,j-i+1))) dp[i][j].push_back(s.substr(i,j-i+1));
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends