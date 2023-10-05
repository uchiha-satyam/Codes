//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	vector<long long> v(26,0),v1(26,0);
        long long count=0,s1=0,val=0,ans=0,count1=0,s2=0;
        for(int i=0;i<s.size();++i){
            if(v1[s[i]-'a']==0)
            ++count;
            if(v[s[i]-'a']==0)
            ++count1;
            v[s[i]-'a']++;
            v1[s[i]-'a']++;
            if(count1>k){
                for(;s2<=s1;++s2){
                    v[s[s2]-'a']--;
                    if(v[s[s2]-'a']==0)
                    {
                        count1--;
                        val=0;
                        ++s2;
                        break;
                    }
                }
            }
            if(count==k){
             for(;s1<=i;++s1){
                 v1[s[s1]-'a']--;
                 if(v1[s[s1]-'a']==0){
                     count--;
                     ++val;
                     ++s1;
                     break;
                 }
                 val++;
             }
        }
        //cout << val << "\n";
         ans+=val;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends