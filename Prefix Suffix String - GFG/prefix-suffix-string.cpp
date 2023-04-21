//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Trie
{
    public:
    Trie* next[26];
    void insert(string str)
    {
        Trie* root = this;
        for(int i=0; i<str.size(); i++)
        {
            if(!root->next[str[i]-'a']) root->next[str[i]-'a'] = new Trie();
            root = root->next[str[i]-'a'];
        }
        root = this;
        for(int i=str.size()-1; i>=0; i--)
        {
            if(!root->next[str[i]-'a']) root->next[str[i]-'a'] = new Trie();
            root = root->next[str[i]-'a'];
        }
    }
    bool search(string str)
    {
        Trie* root = this;
        bool flag = true;
        for(int i=0; i<str.size(); i++)
        {
            if(!root->next[str[i]-'a'])
            {
                flag = false;
                break;
            }
            root = root->next[str[i]-'a'];
        }
        if(flag) return flag;
        root = this;
        for(int i=str.size()-1; i>=0; i--)
        {
            if(!root->next[str[i]-'a']) return false;
            root = root->next[str[i]-'a'];
        }
        return true;
    }
};

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie* root = new Trie();
        for(int i=0; i<s1.size(); i++)
        root->insert(s1[i]);
        int count = 0;
        for(int i=0; i<s2.size(); i++)
        {
            if(root->search(s2[i]))
            {
                // cout<<s2[i]<<endl;
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends