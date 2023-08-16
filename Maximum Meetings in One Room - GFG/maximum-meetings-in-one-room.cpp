//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,int>> vc;
        map<pair<int,int>,int> mp;
        for(int i=0; i<N; i++)
        {
            vc.push_back({F[i],S[i]});
            if(!mp.count(vc[i]))
            mp[vc[i]] = i+1;
        }
        sort(vc.begin(),vc.end());
        int et = -1;
        vector<int> ans;
        for(int i=0; i<N; i++)
        {
            if(vc[i].second<=et) continue;
            ans.push_back(mp[vc[i]]);
            et = vc[i].first;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends