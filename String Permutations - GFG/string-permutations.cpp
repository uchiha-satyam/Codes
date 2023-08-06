//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        sort(S.begin(),S.end());
        int fact[] = {1,1,2,6,24,120};
        int perm[26] = {0};
        for(auto& x : S)
        perm[x-'A']++;
        int prod = 1;
        for(int i=0; i<26; i++)
        {
            prod *= fact[perm[i]];
        }
        // cout<<prod<<endl;
        ans.insert(ans.end(),prod,S);
        while(next_permutation(S.begin(),S.end()))
        {
            ans.insert(ans.end(),prod,S);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends