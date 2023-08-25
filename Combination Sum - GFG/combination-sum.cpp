//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int> st;
        for(int i=0; i<A.size(); i++)
        st.insert(A[i]);
        vector<int> nums(st.begin(),st.end());
        int n = nums.size();
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(B+1));
        for(int j=0; j<=B; j++)
        {
            for(int i=0; i<=n; i++)
            {
                if(j==0)
                {
                    dp[i][j].push_back(vector<int>(n,0));
                    continue;
                }
                if(i>0)
                {
                    for(auto& v : dp[i-1][j])
                    dp[i][j].push_back(v);
                    int val = nums[i-1];
                    while(val<=j)
                    {
                        for(auto v : dp[i-1][j-val])
                        {
                            v[i-1] = val/nums[i-1];
                            dp[i][j].push_back(v);
                        }
                        val += nums[i-1];
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto& v : dp[n][B])
        {
            vector<int> vec;
            for(int i=0; i<n; i++)
            {
                while(v[i])
                {
                    vec.push_back(nums[i]);
                    v[i]--;
                }
            }
            ans.push_back(vec);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends