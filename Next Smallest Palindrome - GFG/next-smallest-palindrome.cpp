//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
        // code here
        bool flag = false;
        int l = 0, r = n-1;
        while(l<r)
        {
            if(num[l]>num[r]) flag = true;
            else if(num[l]<num[r]) flag = false;
            num[r] = num[l];
            l++;
            r--;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++) ans[i] = num[i];
        if(flag) return ans;
        if(n%2) l = r = n/2;
        else l = n/2 - 1, r = n/2;
        int rem = 1;
        while(rem&&r<n)
        {
            ans[l]++;
            if(ans[l]%10==0) ans[l] = 0;
            else rem = 0;
            ans[r] = ans[l];
            l--;
            r++;
        }
        if(rem==0) return ans;
        ans.push_back(rem);
        ans[0] = rem;
        return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends