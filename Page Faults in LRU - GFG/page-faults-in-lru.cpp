//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int ans = 1;
        int l = 0, r = 0, pos = 1;
        while(pos<N)
        {
            int x = -1;
            for(int i=l; i<=r; i++)
            if(pages[i]==pages[pos])
            x = i;
            if(x==-1)
            {
                if(r-l+1==C) l++;
                r++;
                ans++;
            }
            else
            {
                for(int i=x; i>l; i--) swap(pages[i],pages[i-1]);
                r++;
                l++;
            }
            pos++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends