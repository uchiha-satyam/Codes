//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        int req = 0;
        int arr[26] = {0};
        unordered_set<char> st;
        for(auto& x : p)
        {
            arr[x-'a']--;
            st.insert(x);
            req++;
        }
        int l = 0, r = -1, n = s.length();
        int size = INT_MAX, al, ar;
        while(r<n)
        {
            r++;
            if(st.count(s[r]))
            {
                arr[s[r]-'a']++;
                if(arr[s[r]-'a']<=0) req--;
            }
            while(req==0&&l<=r)
            {
                if((r-l+1)<size)
                {
                    al = l;
                    ar = r;
                    size = r-l+1;
                }
                if(st.count(s[l]))
                {
                    arr[s[l]-'a']--;
                    if(arr[s[l]-'a']<0) req++;
                }
                l++;
            }
        }
        if(size==INT_MAX) return "-1";
        return s.substr(al,size);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends