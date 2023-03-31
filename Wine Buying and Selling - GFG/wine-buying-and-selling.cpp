//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      //Code here.
      vector<pair<int,int>> pos, neg;
      for(int i=0; i<n; i++)
      {
          if(arr[i]>0)
          {
              pos.push_back(make_pair(arr[i],i));
          }
          if(arr[i]<0)
          {
              neg.push_back(make_pair(arr[i]*-1,i));
          }
      }
      int p1=0, p2=0;
      long long sum = 0;
      while(p1<pos.size()&&p2<neg.size())
      {
          if(pos[p1].first>neg[p2].first)
          {
              pos[p1].first -= neg[p2].first;
              sum += neg[p2].first*(abs(neg[p2].second-pos[p1].second));
              p2++;
          }
          else if(pos[p1].first<neg[p2].first)
          {
              neg[p2].first -= pos[p1].first;
              sum += pos[p1].first*(abs(neg[p2].second-pos[p1].second));
              p1++;
          }
          else
          {
              sum += pos[p1].first*(abs(neg[p2].second-pos[p1].second));
              p1++;
              p2++;
          }
      }
      return sum;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends