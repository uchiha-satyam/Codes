//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        int s = m[str[0]];
        int prev = m[str[0]];
        for(int i=1; i<str.length(); i++)
        {
            int v = m[str[i]];
            if(v==prev)
            {
                s += v;
            }
            else if(v<prev)
            {
                sum += s;
                s = v;
            }
            else
            {
                sum += v-s;
                s = 0;
            }
            prev = v;
        }
        sum += s;
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends