//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    void add(string& s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        string result = "";
        int rem = 0;
        int p1 = n1-1, p2 = n2-1;
        while(p1>=0||p2>=0||rem!=0)
        {
            int x1 = 0, x2 = 0;
            if(p1>=0) x1 = s1[p1] - '0';
            if(p2>=0) x2 = s2[p2] - '0';
            int sum = x1 + x2 + rem;
            rem = sum/10;
            char ch = sum%10 + '0';
            result.push_back(ch);
            p1--;
            p2--;
        }
        reverse(result.begin(),result.end());
        s1 = result;
    }
    string multiply(string& s1, char ch, int x)
    {
        string  result = "";
        int p = s1.size()-1;
        int rem = 0;
        while(p>=0||rem!=0)
        {
            int v1 = 0, v2 = 0;
            if(p>=0) v1 = s1[p] - '0';
            v2 = ch - '0';
            int prod = v1*v2 + rem;
            rem = prod/10;
            char c = prod%10 + '0';
            result.push_back(c);
            p--;
        }
        reverse(result.begin(),result.end());
        for(int i=0; i<x; i++) result.push_back('0');
        return result;
    }
    public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        //Your code here
        
        // string result = "";
        // cout<<"Multiply: "<<multiply(s1,s2[0],2)<<endl;
        // add(s1,s2);
        // cout<<"Add: "<<s1<<endl;
        // return s1;
        
        bool flag = false;
        if(s1[0]=='-'&&s2[0]=='-')
        {
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
        if(s1[0]=='-')
        {
            s1 = s1.substr(1);
            flag = true;
        }
        if(s2[0]=='-')
        {
            s2 = s2.substr(1);
            flag = true;
        }
        while(s1[0]=='0') s1 = s1.substr(1);
        while(s2[0]=='0') s2 = s2.substr(1);
        // cout<<s1<<" "<<s2<<endl;
        int n1 = s1.size(), n2 = s2.size();
        string result = "";
        for(int i=n2-1; i>=0; i--) add(result,multiply(s1,s2[i],n2-1-i));
        if(flag) result = "-" + result;
        return result;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends