//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string a){
        int max=0,p=0,q=0,c=0,ans=INT_MIN;
        for(int i=0;i<n;++i){
            if(a[i]=='O'&&m==0){
                if(ans<max)
                ans=max;
                for(int j=p;j<n;++j){
                    if(a[j]=='A'&&q==1){
                        p=j;
                        q=0;
                        break;
                    }
                    if(a[j]=='A'&&q==0)
                    --max;
                    else{
                        --max;
                        ++m;
                        q=1;
                    }
                }
            }
            if(a[i]=='O'&&m>0){
                ++max;
                --m;
            }
            else
            ++max;
        }
        if(ans==INT_MIN)
        ans=max;
        else if(ans<max+m)
        ans=max+m;
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends