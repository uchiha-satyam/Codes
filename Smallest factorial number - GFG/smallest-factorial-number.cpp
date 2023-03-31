//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            //complete the function here
            int sum = 0, ans = 0, prev = 0;
            unordered_map<int,int> m;
            while(sum<n)
            {
                ans += 5;
                prev = 0;
                if(m.count(ans/5)) prev = m[ans/5];
                m[ans] = prev + 1;
                sum += m[ans];
            }
            return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends