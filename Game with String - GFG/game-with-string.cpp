//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n = s.length();
        vector<int> oc(26,0);
        for(int i=0; i<n; i++)
        {
            oc[s[i]-'a']++;
        }
        map<int,int,greater<int>> m;
        for(int i=0; i<26; i++)
        {
            m[oc[i]]++;
        }
        while(k>0)
        {
            int o1 = m.begin()->first;
            int o2 = 0;
            auto it = m.begin();
            it++;
            if((it)!=m.end()) o2 = (it)->first;
            int c = m.begin()->second;
            int t = (o1-o2)*c;
            if(t<=k)
            {
                if(o2!=0) (it)->second += c;
                m.erase(m.begin());
                k -= t;
            }
            else
            {
                int d = k/c, r = k%c;
                m.erase(m.begin());
                m[o1-d-1] += r;
                m[o1-d] += c-r;
                k = 0;
            }
        }
        int sum = 0;
        for(auto& x : m)
        sum += (x.first)*(x.first)*(x.second);
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends