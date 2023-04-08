//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    void replace(string& s, char a, char b)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==a) s[i] = b;
            else if(s[i]==b) s[i] = a;
        }
    }
public:
    string chooseandswap(string a){
        // Code Here
        unordered_map<char,int> oc;
        priority_queue<char,vector<char>,greater<char>> pq;
        int n = a.length();
        for(int i=0; i<n; i++)
        {
            if(!oc.count(a[i])) pq.push(a[i]);
            oc[a[i]]++;
        }
        char m = (char)(65);
        // pq.pop();
        for(int i=0; i<n; i++)
        {
            if(a[i]<=m)
            {
                oc[a[i]]--;
            }
            else if(a[i]==pq.top())
            {
                m = pq.top();
                pq.pop();
            }
            else
            {
                // cout<<a[i]<<" "<<pq.top()<<endl;
                replace(a,a[i],pq.top());
                break;
            }
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends