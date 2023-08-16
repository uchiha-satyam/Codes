//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        map<int,int> mp;
        for(int i=0; i<n; i++)
        mp[price[i]] += i+1;
        int ans = 0;
        for(auto& x : mp)
        {
            int c = k/x.first;
            if(c>=x.second)
            {
                ans += x.second;
                k -= x.first * x.second;
            }
            else
            {
                ans += c;
                break;
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends