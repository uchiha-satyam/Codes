//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
    public:
    Node* data[26];
};

void insert(string& s, Node* root, vector<string>& ans, string& pattern)
{
    string str = "";
    Node* temp = root;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]<65||s[i]>90) continue;
        str += s[i];
        if(str==pattern) ans.push_back(s);
        if(!root->data[s[i]-'A']) root->data[s[i]-'A'] = new Node();
        root = root->data[s[i]-'A'];
    }
    root = temp;
}

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        Node* root = new Node();
        vector<string> ans;
        for(auto& x : Dictionary)
        {
            insert(x,root,ans,Pattern);
        }
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends