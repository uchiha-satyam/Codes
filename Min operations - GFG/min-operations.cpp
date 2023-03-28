//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        // code here
        int x = 0, mask = 1;
        for(int i=0; i<8; i++)
        {
            // cout<<mask<<endl;
            if(((a&mask)!=0)&&((b&mask)!=0))
            {
                x += mask;
                // cout<<x;
            }
            mask<<=1;
        }
        if(a==b) return 0;
        if(a==x||b==x) return 1;
        else return 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends