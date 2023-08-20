//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = 0;
        vector<int> sum(m,0);
        for(int i=0; i<n; i++)
        {
            vector<int> v1(m,0), v2(m,0);
            for(int j=0; j<m; j++)
            if(M[i][j]) sum[j]++;
            else sum[j] = 0;
            stack<pair<int,int>> st;
            for(int j=m-1; j>=0; j--)
            {
                while(!st.empty()&&st.top().first>=sum[j]) st.pop();
                if(st.empty()) v1[j] = m;
                else v1[j] = st.top().second;
                st.push({sum[j],j});
            }
            while(!st.empty()) st.pop();
            for(int j=0; j<m; j++)
            {
                while(!st.empty()&&st.top().first>=sum[j]) st.pop();
                if(st.empty()) v2[j] = -1;
                else v2[j] = st.top().second;
                st.push({sum[j],j});
            }
            for(int j=0; j<m; j++)
            if(sum[j]*(v1[j]-v2[j]-1)>ans)
            {
                ans = sum[j]*(v1[j]-v2[j]-1);
                // cout<<i<<" "<<j<<" "<<v1[j]<<" "<<v2[j]<<endl;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends