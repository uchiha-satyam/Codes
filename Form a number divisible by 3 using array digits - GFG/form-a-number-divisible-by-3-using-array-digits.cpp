//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int sum(int n)
    {
        int s = 0;
        while(n>0)
        {
            s += n%10;
            n /= 10;
        }
        return s;
    }
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int s = 0;
        for(int i=0; i<N; i++)
        s += sum(arr[i]);
        if(s%3==0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends