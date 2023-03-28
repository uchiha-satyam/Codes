//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m)
    {
        // unordered_map<int,unordered_set<int>> d;
        unordered_map<int,unordered_set<int>> av, gr;
        for(int i=0; i<m; i++)
        {
            av[danger[i][0]].insert(danger[i][1]);
            av[danger[i][1]].insert(danger[i][0]);
            gr[danger[i][0]].insert(danger[i][0]);
            gr[danger[i][1]].insert(danger[i][1]);
        }
        vector<string> ans(n,"Yes");
        string no = "No";
        vector<int> p(n+1);
        for(int i=0; i<=n; i++)
        {
            p[i] = i;
        }
        for(int i=0; i<n; i++)
        {
            int a = mix[i][0];
            int b = mix[i][1];
            int x = a, y = b;
            while(p[x]!=x)
            {
                x = p[x];
            }
            while(p[y]!=y)
            {
                y = p[y];
            }
            bool flag = false;
            for(auto& ch : gr[y])
            {
                if(av[x].count(ch))
                {
                    flag = true;
                    break;
                }
            }
            // if(av[x].count(b)||av[y].count(a))
            if(flag)
            {
                ans[i] = no;
            }
            else
            {
                p[y] = x;
                for(auto& ch : av[y])
                {
                    av[x].insert(ch);
                }
                for(auto& ch : gr[y])
                {
                    gr[x].insert(ch);
                }
                // av[y].clear();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends