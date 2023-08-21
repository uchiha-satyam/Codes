//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int mod = 1<<20;
        int pow(int a, int b)
        {
            if(a==0||a==1||b==1) return a;
            if(b==0) return 1;
            int p = pow(a,b/2);
            p *= p;
            p %= mod;
            if(b%2) p *= a;
            p %= mod;
            return p;
        }
        bool compare(string s1, string s2)
        {
            if(s1.size()!=s2.size()) return false;
            for(int i=0; i<s1.size(); i++)
            if(s1[i]!=s2[i]) return false;
            return true;
        }
        int hash(string s, unordered_map<char,int>& mp, int& unq)
        {
            int mask = s.size();
            int value = 0;
            for(auto& x : s)
            {
                if(!mp.count(x)) return -1;
                value += mp[x] * pow(unq,mask);
                value %= mod;
                mask--;
            }
            return value;
        }
        void rollHash(int& value, int& unq, int& mask, unordered_map<char,int>& mp, char rem, char add)
        {
            value = (value - mp[rem]*pow(unq,mask) + mod)%mod;
            value *= unq;
            value %= mod;
            value += mp[add]*unq;
            value %= mod;
        }
        void rk(unordered_map<char,int>& mp, int& unq, string txt, string pat, int& target, vector<int>& ans)
        {
            int n = txt.size(), m = pat.size();
            int value = -1;
            int l = 0, r = m-1;
            value = hash(txt.substr(l,m),mp,unq);
            while(r<n)
            {
                if(value==target&&compare(txt.substr(l,m),pat)) ans.push_back(l+1);
                l++;
                r++;
                if(r>=n) break;
                if(value==-1) value = hash(txt.substr(l,m),mp,unq);
                else rollHash(value,unq,m,mp,txt[l-1],txt[r]);
            }
        }
        vector<int> search(string pat, string txt)
        {
            //code here.
            unordered_map<char,int> mp;
            int unq = 0;
            for(auto& x : pat)
            {
                if(!mp.count(x))
                {
                    mp[x] = ++unq;
                }
            }
            int value = hash(pat,mp,unq);
            vector<int> ans;
            rk(mp,unq,txt,pat,value,ans);
            if(ans.empty()) ans.push_back(-1);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends