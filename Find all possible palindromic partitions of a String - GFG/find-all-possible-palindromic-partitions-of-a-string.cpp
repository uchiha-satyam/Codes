//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    void traverse(vector<vector<bool>>& vec, vector<string>& word, vector<vector<string>>& ans, int idx, int& n, string& str)
    {
        if(idx==n)
        {
            ans.push_back(word);
            return;
        }
        for(int j=idx; j<n; j++)
        {
            if(vec[idx][j])
            {
                word.push_back(str.substr(idx,j-idx+1));
                traverse(vec,word,ans,j+1,n,str);
                word.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n = S.size();
        vector<vector<bool>> vec(n,vector<bool>(n,false));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    vec[i][j] = true;
                    continue;
                }
                if(S[i]==S[j]) vec[i][j] = true;
                if(vec[i][j]&&i+1<=j-1) vec[i][j] = vec[i+1][j-1];
            }
        }
        vector<vector<string>> ans;
        vector<string> word;
        traverse(vec,word,ans,0,n,S);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends