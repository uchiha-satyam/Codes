//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        //Code Here
        int n = a.size(), m = a[0].size();
        int maxSize = -1, rs, re, cs, ce;
        for(int i=0; i<n; i++)
        {
            vector<int> vec(m,0);
            for(int j=i; j<n; j++)
            {
                int sum = 0;
                unordered_map<int,int> mp;
                for(int k=0; k<m; k++)
                {
                    vec[k] += a[j][k];
                    sum += vec[k];
                    if(sum==0)
                    {
                        int size = (j-i+1)*(k+1);
                        if((size>maxSize)||(size==maxSize&&((0<cs)||(0==cs&&i<rs)||(0==cs&&i==rs&&(j-i+1)>(re-rs+1)))))
                        {
                            maxSize = size;
                            rs = i;
                            re = j;
                            cs = 0;
                            ce = k;
                        }
                    }
                    else if(mp.count(sum))
                    {
                        int size = (j-i+1)*(k-mp[sum]);
                        if((size>maxSize)||(size==maxSize&&(((mp[sum]+1)<cs)||((mp[sum]+1)==cs&&i<rs)||((mp[sum]+1)==cs&&i==rs&&(j-i+1)>(re-rs+1)))))
                        {
                            maxSize = size;
                            rs = i;
                            re = j;
                            cs = mp[sum]+1;
                            ce = k;
                        }
                    }
                    else
                    {
                        mp[sum] = k;
                    }
                }
            }
        }
        if(maxSize==-1) return vector<vector<int>>();
        vector<vector<int>> ans(re-rs+1,vector<int>(ce-cs+1));
        for(int i=rs; i<=re; i++)
        {
            for(int j=cs; j<=ce; j++)
            {
                ans[i-rs][j-cs] = a[i][j];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends