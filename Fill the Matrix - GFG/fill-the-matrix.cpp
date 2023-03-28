//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        int x1 = y-1, x2 = M-y;
        int y1 = x-1, y2 = N-x;
        vector<int> X = {x1,x2};
        vector<int> Y = {y1,y2};
        int ans = INT_MIN;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ans = max(ans,2*min(X[i],Y[j])+abs(X[i]-Y[j]));
                // cout<<X[i]<<" "<<Y[j]<<endl;
            }
        }
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
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends