//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void helper(vector<int>& s)
    {
        for(int i=s.size()-2; i>=0; i--)
        {
            s[i] += s[i+1];
        }
    }
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        helper(S1);
        helper(S2);
        helper(S3);
        int p1=0, p2=0, p3=0;
        while(p1<N1&&p2<N2&&p3<N3)
        {
            if(S1[p1]==S2[p2]&&S3[p3]==S1[p1]) return S1[p1];
            if(S1[p1]>=S2[p2]&&S1[p1]>=S3[p3]) p1++;
            else if(S2[p2]>=S1[p1]&&S2[p2]>=S3[p3]) p2++;
            else p3++;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends