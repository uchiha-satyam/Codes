//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    string fixedWidth(int value)
    {
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "%.*d", 2, value);
        return buffer;
    }
    public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        map<string,string> mp;
        unordered_map<string,vector<string>> ump;
        for(auto& x : string_list)
        {
            vector<int> vec(26,0);
            for(auto& ch : x) vec[ch-'a']++;
            string converted = "";
            for(auto& v : vec) converted += fixedWidth(v);
            if(!ump.count(converted)) mp[x] = converted;
            ump[converted].push_back(x);
        }
        for(auto& p : mp)
        ans.push_back(ump[p.second]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends