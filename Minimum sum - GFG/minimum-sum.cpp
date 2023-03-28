//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    string sum(string& s1, string& s2)
    {
        string ans = "";
        char rem = '0';
        int p1 = s1.length()-1;
        int p2 = s2.length()-1;
        while(p1>=0||p2>=0)
        {
            char a = '0';
            int s = 0;
            if(p1>=0&&p2>=0)
            {
                s = (s1[p1]-'0') + (s2[p2]-'0') + (rem-'0');
                p1--;
                p2--;
            }
            else if(p1>=0)
            {
                s = (s1[p1]-'0') + (rem-'0');
                p1--;
            }
            else
            {
                s = (s2[p2]-'0') + (rem-'0');
                p2--;
            }
            a = s%10 + '0';
            s /= 10;
            rem = s%10 + '0';
            ans = a + ans;
        }
        if(rem!='0') ans = rem + ans;
        return ans;
    }
public:
    string solve(int arr[], int n) {
        // code here
        char a[n];
        for(int i=0; i<n; i++)
        a[i] = '0' + arr[i];
        sort(a,a+n);
        string s[2] = {"",""};
        int p = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]=='0') continue;
            s[p] += a[i];
            p = (p+1)%2;
        }
        // cout<<s[0]<<endl<<s[1]<<endl;
        return sum(s[0],s[1]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends