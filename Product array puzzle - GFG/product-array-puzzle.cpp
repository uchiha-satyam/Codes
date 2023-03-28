//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here
        unsigned long long l = 1;
        vector<long long> ans(n,0);
        int z = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=0) l*=nums[i];
            else z++;
        }
        if(z>=2) return ans;
        else if(z==1)
        {
            for(int i=0; i<n; i++)
            if(nums[i]==0) ans[i] = l;
            return ans;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                ans[i] = l/nums[i];
            }
            return ans;
        }
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends